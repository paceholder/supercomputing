/**
 * Initialization step - parse the input file, compute data distribution, initialize LOCAL computational arrays
 *
 * @date 22-Oct-2012
 * @author V. Petkov
 */

#include "initialization.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <metis.h>
#include <mpi.h>

#include "util_read_files.h"

void allocate_memory_for_distributed_arrays(double** var,
                                            double** cgup,
                                            double** oc,
                                            double** cnorm,
                                            double** bn,
                                            double** be,
                                            double** bs,
                                            double** bw,
                                            double** bh,
                                            double** bl,
                                            double** bp,
                                            int array_size) {

    *var = (double*) calloc(array_size, sizeof(double));
    *cgup = (double*) calloc(array_size, sizeof(double));
    *oc = (double*) calloc(array_size, sizeof(double));
    *cnorm = (double*) calloc(array_size, sizeof(double));

    *bn = (double*) calloc(array_size, sizeof(double));
    *be = (double*) calloc(array_size, sizeof(double));
    *bs = (double*) calloc(array_size, sizeof(double));
    *bw = (double*) calloc(array_size, sizeof(double));
    *bh = (double*) calloc(array_size, sizeof(double));
    *bl = (double*) calloc(array_size, sizeof(double));
    *bp = (double*) calloc(array_size, sizeof(double));
}


void calculate_number_of_elements_and_offsets(int** number_of_elements_in_partitions,
                                              int** partitions_offsets,
                                              int** recv_count,
                                              int number_of_elements) {
    int neighbours_count;
    int my_rank;
    int i;


    MPI_Comm_size(MPI_COMM_WORLD, &neighbours_count);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);


    // we should know how many elements are in each partition
    *number_of_elements_in_partitions = (int*) calloc(neighbours_count, sizeof(int));
    memset(*number_of_elements_in_partitions, 0, neighbours_count * sizeof(int));

    MPI_Request requests[neighbours_count];

    printf("local LCC\n");
    printf("myrank %d\n", my_rank);
    for ( i = 0; i < neighbours_count; ++i ) {
        // checks whether we communicate with neighbour #i
        if ((*recv_count)[i] > 0 ) {
            MPI_Isend(&number_of_elements, 1, MPI_INT, i, 10, MPI_COMM_WORLD, &requests[i]);
        }
    }

    for ( i = 0; i < neighbours_count; ++i ) {
        if ((*recv_count)[i] > 0 ) {
            // then we receive from the same neighbour
            MPI_Status status;
            MPI_Recv(&(*number_of_elements_in_partitions)[i], 1, MPI_INT, i, 10, MPI_COMM_WORLD, &status);
        }
    }

    MPI_Status status;
    for ( i = 0; i < neighbours_count; ++i ) {
        if ((*recv_count)[i] > 0 ) {
            MPI_Wait(&requests[i], &status);
        }
    }

/*
    for ( i = 0; i < neighbours_count; ++i ) {
        printf("rank %d, neighbour %d elements %d\n", my_rank, i, elements_in_partitions[i]);
    }

    */
    
    // an array of offsets for ghost layers from each neighbour to map lcc correctly 
    *partitions_offsets = (int*) calloc(neighbours_count, sizeof(int));
    (*partitions_offsets)[0] = 1;
    for ( i = 1; i < neighbours_count; ++i )
        (*partitions_offsets)[i] = (*partitions_offsets)[i-1] + (*number_of_elements_in_partitions)[i];
}



void fill_local_lcc(int** glob_lcc, 
                    int*** lcc,
                    int** number_of_elements_in_partitions,
                    int** partitions_offsets,
                    int number_of_elements,
                    idx_t ne,
                    int** recv_count,
                    int** local_global_index,
                    int** global_local_index,
                    idx_t** epart) {
    int i;
    int j;
    int my_rank;
    int neighbours_count;

    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &neighbours_count);

    // cound additional place for send and receive
    int total_recv = 0;
    for ( i = 0; i < neighbours_count; ++i )
        total_recv += (*number_of_elements_in_partitions)[i];


    // allocate new array for remapped lcc
    *lcc = (int**) calloc(number_of_elements, sizeof(int*));

    // current position of ghost chell index inside ghost layers pats
//    int offsets_inside_partition[neighbours_count];
//    memset(offsets_inside_partition, 0, neighbours_count * sizeof(int));

    for ( i = 0; i < number_of_elements; ++i ) {
        // memory for one cell of lcc
        (*lcc)[i] = calloc(6, sizeof(int));

        // take global index for current local element
        int gl_index = (*local_global_index)[i];
    
        int* cells = glob_lcc[gl_index];

        // check cells around
        for ( j = 0; j < 6; ++j ) {
            int old_global_index = cells[j];

            // stored in remapped lcc
            int new_local_index;

            /*        indexing
             *
             * | inner cells | recv1 | recv2 ... | outer one cell |
             */

            // outer cell - index larger than total number of inner cells
            if (old_global_index > ne-1)
                // very last cell
                new_local_index = number_of_elements-1 + total_recv + 1;
            // inner cells and ghost layer
            else {
                /* 
                 * global index points to neighbour 
                 * that means it is a ghost layer 
                 * */
                int partition = (*epart)[old_global_index];
                if ( partition != my_rank ) {
                    // local number for ghost cell in neighbouring partition 
                    new_local_index = number_of_elements + (*partitions_offsets)[partition] 
                                                         + (*global_local_index)[old_global_index];
                } else
                    // link to inner cell
                    new_local_index = (*global_local_index)[old_global_index];

            }

            (*lcc)[i][j] = new_local_index;
        }
    }

/*
    for ( i = 0; i < neighbours_count; ++i ) {
        printf("rank %d neighbour: %d inner_offset %d\n", my_rank, i, offsets_inside_partition[i]);
        }
*/
}


// count number of elements for each process
int get_number_of_local_elements(idx_t ne, idx_t** epart) {
    int i;
    int my_rank;
    int number_of_elements = 0;


    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    
    for ( i = 0; i < ne; ++i ) {
        if ((*epart)[i] == my_rank)
            number_of_elements += 1;
    }

    return number_of_elements;
}

void allocate_memory_for_mapping_arrays(int** local_global_index,
                                        int** global_local_index,
                                        int number_of_local_elements,
                                        int number_of_global_elements) {
    *local_global_index = (int*) calloc(number_of_local_elements, sizeof(int));
    *global_local_index = (int*) calloc(number_of_global_elements, sizeof(int));
}



void fill_local_arrays(int** local_global_index,
                       int** global_local_index,
                       double** cgup,
                       double** be,
                       double** bs,
                       double** bw,
                       double** bh,
                       double** bl,
                       double** bp,

                       double* glob_cgup,
                       double* glob_be,
                       double* glob_bs,
                       double* glob_bw,
                       double* glob_bh,
                       double* glob_bl,
                       double* glob_bp,

                       idx_t ne,
                       idx_t** epart) {
    int i;
    int my_rank;
    int neighbours_count;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);    /// get number of processes
    MPI_Comm_size(MPI_COMM_WORLD, &neighbours_count);    /// get number of processes

    int current_index[neighbours_count];
    for ( i = 0; i < neighbours_count; ++i )
        current_index[i] = 0;

    for ( i = 0; i < ne; ++i ) {
        int partition = (*epart)[i];

        if ( partition == my_rank ) {
            (*local_global_index)[current_index[partition]] = i;

            (*cgup)[current_index[partition]] = glob_cgup[i];
            (*be)[current_index[partition]] = glob_be[i];
            (*bs)[current_index[partition]] = glob_bs[i];
            (*bw)[current_index[partition]] = glob_bw[i];
            (*bh)[current_index[partition]] = glob_bh[i];
            (*bl)[current_index[partition]] = glob_bl[i];
            (*bp)[current_index[partition]] = glob_bp[i];
        }

        (*global_local_index)[i] = current_index[partition];

        ++current_index[partition];
    }
}




void partitioning(idx_t ne, idx_t nn,
                  int** elems,
                  char* part_type,
                  idx_t** epart, idx_t** npart)
{
    int i;
    int num_procs;

    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);    /// get number of processes

    /* two arrays for setting graph structure */

    idx_t* eptr = (idx_t*) malloc((ne + 1) * sizeof(idx_t));
    for ( i = 0; i < ne + 1; ++i )
        eptr[i] = i * 8;

    idx_t* eind = (idx_t*) malloc(ne * sizeof(idx_t) * 8);

    for ( i = 0; i < ne * 8; ++i )
        eind[i] = (*elems)[i];

    /* output metis arrays */

    *epart = (idx_t*) calloc(ne, sizeof(idx_t));
    *npart = (idx_t*) calloc(nn, sizeof(idx_t));

    /* additional metis parameters */ 

    idx_t options[METIS_NOPTIONS];
    idx_t obvl;
    idx_t ncommon = 4;
    idx_t procs = num_procs;

    METIS_SetDefaultOptions(options);

    /* different strategies for domain partitioninig */
    if ( strcmp(part_type, "dual") == 0 ) {
        if (METIS_OK != METIS_PartMeshDual(&ne, &nn,
                                            eptr, eind,
                                            NULL, NULL, &ncommon,
                                            &procs, NULL, options,
                                            &obvl, *epart, *npart))
            printf("Error in METIS_PartMeshDual\n");
    } else if ( strcmp(part_type, "nodal") == 0 ) {
        METIS_PartMeshNodal(&ne, &nn,
                            eptr, eind,
                            NULL, NULL,
                            &procs,
                            NULL, options,
                            &obvl, *epart, *npart);
    } else if (strcmp(part_type, "classical") == 0) {
        int elems_per_node = ne / procs + 1;

        for ( i = 0; i < ne; ++i ) {
            int p = i / elems_per_node;
            (*epart)[i] = p;
        }
    } else {
        printf("unknown partition type\n");
        MPI_Abort(MPI_COMM_WORLD, -1);
    }
}


void fill_send_recv_arrays(int** send_count, int*** send_list,
                           int** recv_count, int*** recv_list,
                           int** glob_lcc,
                           int number_of_elements,
                           idx_t ne,
                           int** local_global_index,
                           int** global_local_index,
                           idx_t** epart
                           ) {
    int i; int j;
    int num_procs;
    int my_rank;

    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    // number of elements sending to neighbours
    *send_count = (int*) calloc(num_procs, sizeof(int));
    *recv_count = (int*) calloc(num_procs, sizeof(int));


    for ( i = 0; i < number_of_elements; ++i ) {
        // global index of current local element
        int global_index = (*local_global_index)[i];

        // 6 directions - 6 neighbours
        for ( j = 0; j < 6; ++j ) {
            // global index of neighbouring cell
            int neighbouring_cell = glob_lcc[global_index][j];

            if ( neighbouring_cell > ne-1 )
                continue;

            // partititon of j-th neighbour
            int partition = (*epart)[neighbouring_cell];

            // we count how many times we send to each neighbour
            if ( partition != my_rank ) {
                (*send_count)[partition] += 1;
                (*recv_count)[partition] += 1;
            }
        }
    }

    *send_list = (int**) calloc(num_procs, sizeof(int*));
    *recv_list = (int**) calloc(num_procs, sizeof(int*));

    for ( i = 0; i < num_procs; ++i ) {
        (*send_list)[i] = (int*) calloc((*send_count)[i], sizeof(int));
        (*recv_list)[i] = (int*) calloc((*recv_count)[i], sizeof(int));
    }

    int* curr_indices = (int*) calloc(num_procs, sizeof(int));
    // traverce all local cells in this partition
    for ( i = 0; i < number_of_elements; ++i ) {
        // global index of current cell
        //int global_index = (*local_global_index)[i];
        int send_global_index = (*local_global_index)[i];
    
        for ( j = 0; j < 6; ++j ) {
            // global index of neighbouring cell
            int neighbouring_cell = glob_lcc[send_global_index][j];

            // skip indices of outer cells
            if ( neighbouring_cell > ne-1 )
                continue;

            int part = (*epart)[neighbouring_cell];

            // we must send information
            if ( part != my_rank ) {
                (*send_list)[part][curr_indices[part]] = (*global_local_index)[send_global_index];
                (*recv_list)[part][curr_indices[part]] = (*global_local_index)[neighbouring_cell];
                curr_indices[part] += 1;
            }
        }
    }

    free(curr_indices);

//    for ( i = 0; i < num_procs; ++i)
//        printf("proc %d   neighbour %d   count %d\n", my_rank, i, (*recv_count)[i]);
}




/**************************************************************************************/


int initialization(char* file_in, char* part_type,
                   int* nintci, int* nintcf, int* nextci, int* nextcf,
                   int*** lcc, 
                   double** bs, double** be, double** bn, 
                   double** bw, double** bl, double** bh, 
                   double** bp, 
                   double** su, 
                   int* points_count,
                   int*** points, int** elems, 
                   double** var, double** cgup, double** oc, double** cnorm, 
                   int** local_global_index, int** global_local_index,

                   int* number_of_elements,
                   int** number_of_elements_in_partitions,
                   int** partitions_offsets,
                   int** send_count, int*** send_list, 
                   int** recv_count, int*** recv_list, 
                   idx_t** epart, idx_t** npart, 
                   int* objval) {


    /********** START INITIALIZATION **********/
    int i = 0;
    int j;
    int num_procs;
    int my_rank;
    idx_t ne;
    idx_t nn;
    *number_of_elements = 0;

    double* glob_bs;
    double* glob_be;
    double* glob_bn;
    double* glob_bw;
    double* glob_bl;
    double* glob_bh;
    double* glob_bp;
    double* glob_cgup;

    int** glob_lcc;


    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);    /// Get current process id
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);    /// get number of processes

    // read-in the input file
    int f_status = read_binary_geo(file_in, nintci, nintcf, nextci, nextcf, &glob_lcc,
                                    &glob_bs, &glob_be, &glob_bn, &glob_bw,
                                    &glob_bl, &glob_bh, &glob_bp,
                                    &glob_cgup,
                                    &*su, &*points_count,
                                    &*points, elems);


    if ( f_status != 0 ) return f_status;


    ne = *nintcf+1;
    nn = *points_count;


    /* partitioning */

    partitioning(ne, nn,
                 elems,
                 part_type,
                 epart, npart);


    *number_of_elements = get_number_of_local_elements(ne, epart);


    allocate_memory_for_distributed_arrays(var,
                                           cgup,
                                           oc,
                                           cnorm,
                                           bn, be,
                                           bs, bw,
                                           bh, bl,
                                           bp,
                                           *number_of_elements);

    allocate_memory_for_mapping_arrays(local_global_index, 
                                       global_local_index, 
                                       *number_of_elements,
                                       ne);


    fill_local_arrays(local_global_index, global_local_index,
                      cgup,
                      be, bs, bw, bh, bl, bp,
                      glob_cgup,
                      glob_be, glob_bs, glob_bw, glob_bh, glob_bl, glob_bp,
                      ne,
                      epart);


    fill_send_recv_arrays(send_count, send_list,
                          recv_count, recv_list,
                          glob_lcc,
                          *number_of_elements,
                          ne,
                          local_global_index,
                          global_local_index,
                          epart);

    calculate_number_of_elements_and_offsets(number_of_elements_in_partitions,
                                             partitions_offsets,
                                             recv_count,
                                             *number_of_elements);
    fill_local_lcc(glob_lcc, lcc, 
                   number_of_elements_in_partitions,
                   partitions_offsets,
                   *number_of_elements, 
                   ne,
                   recv_count, 
                   local_global_index, 
                   global_local_index,
                   epart);


    // free(current_indices);
    // free(glob_var);
    // free(glob_cgup);
    // free(glob_oc);
    // free(glob_cnorm);
    free(glob_bs);
    free(glob_be);
    free(glob_bn);
    free(glob_bw);
    free(glob_bl);
    free(glob_bh);
    free(glob_bp);

    *nintci = 0;
    *nintcf = *number_of_elements -1;

    return 0;
}

