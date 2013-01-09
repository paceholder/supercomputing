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

void allocate_memory_for_mapping_arrays(int** local_global_index,
                                        int number_of_local_elements,
                                        int** global_local_index,
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
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);    /// get number of processes

    int current_index = 0;
    for ( i = 0; i < ne; ++i ) {
        if ( (*epart)[i] == my_rank ) {
            (*local_global_index)[current_index] = i;
            (*global_local_index)[i] = current_index;

            (*cgup)[current_index] = glob_cgup[i];
            (*be)[current_index] = glob_be[i];
            (*bs)[current_index] = glob_bs[i];
            (*bw)[current_index] = glob_bw[i];
            (*bh)[current_index] = glob_bh[i];
            (*bl)[current_index] = glob_bl[i];
            (*bp)[current_index] = glob_bp[i];

            ++current_index;
        }
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
        printf("Elements per node %d\n", elems_per_node);

        for ( i = 0; i < ne; ++i ) {
            int p = i / elems_per_node;
            (*epart)[i] = p;
        }
    } else {
        printf("unknown partition type\n");
        MPI_Abort(MPI_COMM_WORLD, -1);
    }
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
                   int* neighbors_count, 
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

    double* glob_bs;
    double* glob_be;
    double* glob_bn;
    double* glob_bw;
    double* glob_bl;
    double* glob_bh;
    double* glob_bp;
    double* glob_cgup;


    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);    /// Get current process id
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);    /// get number of processes

    // read-in the input file
    int f_status = read_binary_geo(file_in, &*nintci, &*nintcf, &*nextci, &*nextcf, &*lcc,
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


    // filling local_global_index array
    int number_of_elements = 0;

    // count number of elements for each process
    for ( i = 0; i < ne; ++i ) {
        if ((*epart)[i] == my_rank)
            number_of_elements += 1;
    }

    allocate_memory_for_distributed_arrays(var,
                                           cgup,
                                           oc,
                                           cnorm,
                                           bn, be,
                                           bs, bw,
                                           bh, bl,
                                           bp,
                                           number_of_elements);

    allocate_memory_for_mapping_arrays(local_global_index, number_of_elements,
                                       global_local_index, ne);


    fill_local_arrays(local_global_index, global_local_index,
                      cgup,
                      be, bs, bw, bh, bl, bp,
                      glob_cgup,
                      glob_be, glob_bs, glob_bw, glob_bh, glob_bl, glob_bp,
                      ne,
                      epart);



    // number of elements sending to neighbours
    *send_count = (int*) calloc(num_procs, sizeof(int));
    *recv_count = (int*) calloc(num_procs, sizeof(int));


    for ( i = 0; i < number_of_elements; ++i ) {
        // global index of current local element
        int global_index = (*local_global_index)[i];

        // 6 directions - 6 neighbours
        for ( j = 0; j < 6; ++j ) {
            // global index of neighbouring cell
            int neighbouring_cell = (*lcc)[global_index][j];

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

    int* current_indices = (int*) calloc(num_procs, sizeof(int));
    // traverce all local cells in this partition
    for ( i = 0; i < number_of_elements; ++i ) {
        // global index of current cell
        int global_index = (*local_global_index)[i];
    
        for ( j = 0; j < 6; ++j ) {
            // global index of neighbouring cell
            int neighbouring_cell = (*lcc)[global_index][j];

            if ( neighbouring_cell > ne-1 )
                continue;

            int partition = (*epart)[neighbouring_cell];

            // we must send information
            if ( partition != my_rank ) {
                (*send_list)[partition][current_indices[partition]] = global_index;
                (*recv_list)[partition][current_indices[partition]] = neighbouring_cell;
                current_indices[partition] += 1;
            }
        }
    }

//    free(current_indices);

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
    *nintcf = number_of_elements -1;

    return 0;
}

