/**
 * Initialization step - parse the input file, compute data distribution, initialize LOCAL computational arrays
 *
 * @date 22-Oct-2012
 * @author V. Petkov
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <mpi.h>
#include "metis.h"

#include "util_read_files.h"
#include "initialization.h"

void allocate_memory_for_distributed_arrays(int** local_global_index,
                                            double** cgup, 
                                            double** bn,
                                            double** be,
                                            double** bs,
                                            double** bw,
                                            double** bh,
                                            double** bl,
                                            double** bp,
                                            int array_size)
{
    *local_global_index = (int*) calloc(array_size, sizeof(int));
    *cgup = (double*) calloc(array_size, sizeof(double));
    *bn = (double*) calloc(array_size, sizeof(double)); // map local to global
    *be = (double*) calloc(array_size, sizeof(double)); // map local to global
    *bs = (double*) calloc(array_size, sizeof(double)); // map local to global
    *bw = (double*) calloc(array_size, sizeof(double)); // map local to global
    *bh = (double*) calloc(array_size, sizeof(double)); // map local to global
    *bl = (double*) calloc(array_size, sizeof(double)); // map local to global
    *bp = (double*) calloc(array_size, sizeof(double)); // map local to global

}

void send_distributed_arrays(int* local_global_index,
                            double* cgup, 
                            double* bn,
                            double* be,
                            double* bs,
                            double* bw,
                            double* bh,
                            double* bl,
                            double* bp,
                            int ne_send,
                            int proc_receiver)
{
    MPI_Send(local_global_index, ne_send, MPI_INT, proc_receiver, 9, MPI_COMM_WORLD);
    MPI_Send(cgup, ne_send, MPI_DOUBLE, proc_receiver, 10, MPI_COMM_WORLD);
    MPI_Send(be, ne_send, MPI_DOUBLE, proc_receiver, 11, MPI_COMM_WORLD);
    MPI_Send(bn, ne_send, MPI_DOUBLE, proc_receiver, 12, MPI_COMM_WORLD);
    MPI_Send(bw, ne_send, MPI_DOUBLE, proc_receiver, 13, MPI_COMM_WORLD);
    MPI_Send(bs, ne_send, MPI_DOUBLE, proc_receiver, 14, MPI_COMM_WORLD);
    MPI_Send(bh, ne_send, MPI_DOUBLE, proc_receiver, 15, MPI_COMM_WORLD);
    MPI_Send(bl, ne_send, MPI_DOUBLE, proc_receiver, 16, MPI_COMM_WORLD);
    MPI_Send(bp, ne_send, MPI_DOUBLE, proc_receiver, 17, MPI_COMM_WORLD);
}

/**************************************************************************************/


int initialization(char* file_in, char* part_type, int* nintci, int* nintcf, int* nextci,
                   int* nextcf, int*** lcc, double** bs, double** be, double** bn, double** bw,
                   double** bl, double** bh, double** bp, double** su, int* points_count,
                   int*** points, int** elems, double** var, double** cgup, double** oc,
                   double** cnorm, int** local_global_index, int** global_local_index,
                   int* neighbors_count, int** send_count, int*** send_list, int** recv_count,
                   int*** recv_list, int** epart, int** npart, int* objval) {
    /********** START INITIALIZATION **********/
    int i = 0;
    int j;
    int my_rank;
    int num_procs;
    idx_t ne;
    idx_t nn;
    idx_t *ept;
    idx_t *npt;

    double* glob_var; 
    double* glob_cgup;
    double* glob_oc; 
    double* glob_cnorm; 

    double* glob_bs;
    double* glob_be;
    double* glob_bn;
    double* glob_bw;
    double* glob_bl;
    double* glob_bh;
    double* glob_bp;


    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);    /// Get current process id
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);    /// get number of processes
    

    if (my_rank == 0) {

        printf("Before reading the files %d\n", my_rank);

        // read-in the input file
        int f_status = read_binary_geo(file_in, &*nintci, &*nintcf, &*nextci, &*nextcf, &*lcc,
                                       &glob_bs, &glob_be, &glob_bn, &glob_bw, 
                                       &glob_bl, &glob_bh, &glob_bp, 
                                       &*su, &*points_count,
                                       &*points, elems);

        printf("Reading the files %d\n", my_rank);

        if ( f_status != 0 ) return f_status;

        glob_var = (double*) calloc(sizeof(double), (*nextcf + 1));
        glob_cgup = (double*) calloc(sizeof(double), (*nextcf + 1));
        glob_oc = (double*) calloc(sizeof(double), (*nintcf + 1));
        glob_cnorm = (double*) calloc(sizeof(double), (*nintcf + 1));

        // initialize the arrays
        for ( i = 0; i <= 10; i++ ) {
            glob_oc[i] = 0.0;
            glob_cnorm[i] = 1.0;
        }

        for ( i = (*nintci); i <= (*nintcf); i++ ) {
            glob_cgup[i] = 0.0;
            glob_var[i] = 0.0;
        }

        for ( i = (*nextci); i <= (*nextcf); i++ ) {
            (glob_var)[i] = 0.0;
            (glob_cgup)[i] = 0.0;
            (glob_bs)[i] = 0.0;
            (glob_be)[i] = 0.0;
            (glob_bn)[i] = 0.0;
            (glob_bw)[i] = 0.0;
            (glob_bl)[i] = 0.0;
            (glob_bh)[i] = 0.0;
        }

        for ( i = (*nintci); i <= (*nintcf); i++ )
            (glob_cgup)[i] = 1.0 / (glob_bp[i]);


        idx_t options[METIS_NOPTIONS];

        ne = *nintcf+1;
        nn = *points_count;

        idx_t* eptr = (idx_t*) malloc  ((ne + 1) * sizeof(idx_t));
        for(i = 0; i < ne + 1; ++i)
            eptr[i] = i * 8;


        idx_t* eind = (idx_t*) malloc (ne * sizeof(idx_t) * 8);

        for(i = 0; i < ne * 8; ++i)
            eind[i] = (*elems)[i];

        ept = (idx_t*) malloc (ne * sizeof(idx_t));
        npt = (idx_t*) malloc (nn * sizeof(idx_t));

        idx_t obvl;
        idx_t ncommon = 4;
        idx_t procs = num_procs;

        METIS_SetDefaultOptions(options);



        if (strcmp(part_type, "dual") == 0) {
            if (METIS_OK != METIS_PartMeshDual(&ne, &nn, 
                            eptr, eind, 
                            NULL, NULL, &ncommon, 
                            &procs, NULL, options, 
                            &obvl, ept, npt))
                printf("EEEEEEEEERRRRRRRRRORRRRRR!!!\n");
        } else if (strcmp(part_type, "nodal") == 0 ) {
            METIS_PartMeshNodal(&ne, &nn, 
                                eptr, eind, 
                                NULL, NULL, 
                                &procs,
                                NULL, options, 
                                &obvl, ept, npt);
        } else if (strcmp(part_type, "classical") == 0) {


        } else {
            printf("unknown partition type\n");
            MPI_Abort(MPI_COMM_WORLD, -1);
        }
        free(eptr);
        free(eind);
    }


    // distribute lengths of METIS arrays
    MPI_Bcast(&ne, 1, MPI_LONG, 0, MPI_COMM_WORLD);
    MPI_Bcast(&nn, 1, MPI_LONG, 0, MPI_COMM_WORLD);

    if (my_rank != 0) {
        ept = (idx_t*) malloc (ne * sizeof(idx_t));
        npt = (idx_t*) malloc (nn * sizeof(idx_t));
    }


    // distribute METIS arrays
    MPI_Bcast(ept, ne, MPI_LONG, 0, MPI_COMM_WORLD);
    MPI_Bcast(npt, nn, MPI_LONG, 0, MPI_COMM_WORLD);

    MPI_Barrier(MPI_COMM_WORLD);


    int number_of_elements;

    // filling local_global_index array
    int* number_of_elements_arr = 0;
    if (my_rank == 0) {
        number_of_elements_arr = (int*) calloc(num_procs, sizeof(int));

        // count number of elements for each process
        for(i = 0; i < ne; ++i) {
            number_of_elements_arr[ept[i]] += 1;
        }

        // Send number of elements to each process
        for(j = 1; j < num_procs; ++j) {
            MPI_Send(&(number_of_elements_arr[j]), 1, MPI_INT, j, 10, MPI_COMM_WORLD);
        }

        // explicit copyinf for 0 process
        number_of_elements = number_of_elements_arr[0];
    } else {
        // each process gets its number of elements
        MPI_Status status;
        MPI_Recv(&number_of_elements, 1, MPI_INT, 0, 10, MPI_COMM_WORLD, &status);
    }


    allocate_memory_for_distributed_arrays(local_global_index,
                                           cgup,
                                           bn, be,
                                           bs, bw,
                                           bh, bl, 
                                           bp,
                                           number_of_elements);

    MPI_Barrier(MPI_COMM_WORLD);


    if (my_rank == 0) {
        for(j = 1; j < num_procs; ++j) {
            int* local_global_index_send;
            double* cgup_send;
            double* bn_send;
            double* be_send;
            double* bs_send;
            double* bw_send;
            double* bh_send;
            double* bl_send;
            double* bp_send;

            allocate_memory_for_distributed_arrays(&local_global_index_send,
                                                   &cgup_send,
                                                   &bn_send,
                                                   &be_send,
                                                   &bs_send,
                                                   &bw_send,
                                                   &bh_send,
                                                   &bl_send,
                                                   &bp_send,
                                                   number_of_elements_arr[j]);

            int current_index = 0;
            for(i = 0; i < ne; ++i) {
                if (ept[i] == j) {
                    local_global_index_send[current_index] = i;

                    cgup_send[current_index] = glob_cgup[i];
                    be_send[current_index] = glob_be[i];
                    bs_send[current_index] = glob_bs[i];
                    bw_send[current_index] = glob_bw[i];
                    bh_send[current_index] = glob_bh[i];
                    bl_send[current_index] = glob_bl[i];
                    bp_send[current_index] = glob_bp[i];

                    ++current_index; 
                }
            }



            int ne_send = number_of_elements_arr[j];
            if (j != 0) {
                send_distributed_arrays(local_global_index_send,
                                        cgup_send,
                                        bn_send, be_send,
                                        bs_send, bw_send, 
                                        bh_send, bl_send, 
                                        bp_send, ne_send, j);
            } else { // for 0 process we just copy values without MPI
                memcpy(local_global_index, local_global_index_send, ne_send * sizeof(int));
                memcpy(cgup, cgup_send, ne_send * sizeof(double));
                memcpy(bn, bn_send, ne_send * sizeof(double));
                memcpy(be, be_send, ne_send * sizeof(double));
                memcpy(bs, bs_send, ne_send * sizeof(double));
                memcpy(bw, bw_send, ne_send * sizeof(double));
                memcpy(bh, bh_send, ne_send * sizeof(double));
                memcpy(bl, bl_send, ne_send * sizeof(double));
                memcpy(bp, bp_send, ne_send * sizeof(double));
            } 

            free(local_global_index_send);
            free(be_send);
            free(bn_send);
            free(bw_send);
            free(bs_send);
            free(bh_send);
            free(bl_send);
            free(bp_send);
        }

        free(glob_var);
        free(glob_cgup);
        free(glob_oc);
        free(glob_cnorm);
        free(glob_bs);
        free(glob_be);
        free(glob_bn);
        free(glob_bw);
        free(glob_bl);
        free(glob_bh);
        free(glob_bp);
    }


    // all processes receive distributed arrays
    if (my_rank != 0) {
        MPI_Status status;
        MPI_Recv(*local_global_index, number_of_elements, MPI_INT, 0, 9, MPI_COMM_WORLD, &status);
        MPI_Recv(*cgup, number_of_elements, MPI_DOUBLE, 0, 10, MPI_COMM_WORLD, &status);
        MPI_Recv(*be, number_of_elements, MPI_DOUBLE, 0, 11, MPI_COMM_WORLD, &status);
        MPI_Recv(*bn, number_of_elements, MPI_DOUBLE, 0, 12, MPI_COMM_WORLD, &status);
        MPI_Recv(*bw, number_of_elements, MPI_DOUBLE, 0, 13, MPI_COMM_WORLD, &status);
        MPI_Recv(*bs, number_of_elements, MPI_DOUBLE, 0, 14, MPI_COMM_WORLD, &status);
        MPI_Recv(*bh, number_of_elements, MPI_DOUBLE, 0, 15, MPI_COMM_WORLD, &status);
        MPI_Recv(*bl, number_of_elements, MPI_DOUBLE, 0, 16, MPI_COMM_WORLD, &status);
        MPI_Recv(*bp, number_of_elements, MPI_DOUBLE, 0, 17, MPI_COMM_WORLD, &status);
    }

    *nintci = 0;
    *nintcf = number_of_elements -1;

    *epart = (int*) calloc(ne, sizeof(int));
    *npart = (int*) calloc(nn, sizeof(int));

    for(i = 0; i < ne; ++i)
        (*epart)[i] = ept[i];

    for(i = 0; i < nn; ++i)
        (*npart)[i] = npt[i];

    free(ept);
    free(npt);

    return 0;
}

