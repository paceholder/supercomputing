/**
 * Computational loop
 *
 * @file compute_solution.c
 * @date 22-Oct-2012
 * @author V. Petkov
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "mpi.h"

int compute_solution(const int max_iters, int nintci, int nintcf, int nextcf, int** lcc, double* bp,
                     double* bs, double* bw, double* bl, double* bn, double* be, double* bh,
                     double* cnorm, double* var, double *su, double* cgup, double* residual_ratio,
                     int* local_global_index, int* global_local_index, 
                     int number_of_elements,
                     int* number_of_elements_in_partitions,
                     int* partitions_offsets,
                     int* send_count, int** send_list, 
                     int* recv_count, int** recv_list) {
    int iter = 1;
    int if1 = 0;
    int if2 = 0;
    int nor = 1;
    int nor1 = nor - 1;
    int nc = 0;

    int i;

    // allocate arrays used in gccg
    int nomax = 3;

    /** the reference residual*/
    double resref = 0.0;

    /** array storing residuals */
    double *resvec = (double *) calloc(sizeof(double), (nintcf + 1));


    // initialize the reference residual
    for ( nc = nintci; nc <= nintcf; nc++ ) {
        resvec[nc] = su[nc];
        resref = resref + resvec[nc] * resvec[nc];
    }


    MPI_Allreduce(MPI_IN_PLACE, &resref, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);

    resref = sqrt(resref);
    if ( resref < 1.0e-15 ) {
        fprintf(stderr, "Residue sum less than 1.e-15 - %lf\n", resref);
        return 0;
    }

    int my_rank;
    int neighbours_count;
    MPI_Comm_size(MPI_COMM_WORLD, &neighbours_count);    /// get number of processes
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    /* how many cells do we receive */
    int total_recv = 0;
    for ( i = 0; i < neighbours_count; ++i )
        total_recv += number_of_elements_in_partitions[i];

    /** the computation vectors */
    double *direc1 = (double *) calloc(sizeof(double), (nintcf + 1) + total_recv + 1);
    double *direc2 = (double *) calloc(sizeof(double), (nintcf + 1));
    double *adxor1 = (double *) calloc(sizeof(double), (nintcf + 1));
    double *adxor2 = (double *) calloc(sizeof(double), (nintcf + 1));
    double *dxor1 = (double *) calloc(sizeof(double), (nintcf + 1));
    double *dxor2 = (double *) calloc(sizeof(double), (nintcf + 1));

    MPI_Datatype send_datatypes[neighbours_count];

    for ( i = 0; i <  neighbours_count; ++i ) {
        int j;
        int* b = (int*) calloc(send_count[i], sizeof(int));
        for ( j = 0; j < send_count[i]; ++j )
            b[j] = 1;

        MPI_Type_indexed(send_count[i], b, send_list[i], MPI_DOUBLE, &send_datatypes[i]);
        MPI_Type_commit(&send_datatypes[i]);
        free(b);
    }

    MPI_Datatype recv_datatypes[neighbours_count];

    for ( i = 0; i <  neighbours_count; ++i ) {
        int j;
        int* b = (int*) calloc(recv_count[i], sizeof(int));
        for ( j = 0; j < recv_count[i]; ++j )
            b[j] = 1;

        MPI_Type_indexed(recv_count[i], b, recv_list[i], MPI_DOUBLE, &recv_datatypes[i]);
        MPI_Type_commit(&recv_datatypes[i]);
        free(b);
    }

    MPI_Request requests[neighbours_count];
    MPI_Status  statuses[neighbours_count];

    while ( iter < max_iters ) {
        /**********  START COMP PHASE 1 **********/
        // update the old values of direc
        for ( nc = nintci; nc <= nintcf; nc++ ) {
            direc1[nc] = direc1[nc] + resvec[nc] * cgup[nc];
        }

        for ( i = 0; i <  neighbours_count; ++i ) {
            if ( recv_count[i] > 0 ) {
                MPI_Isend(direc1, 1, send_datatypes[i], i, 10, MPI_COMM_WORLD, &requests[i]);
            }
        }

        for ( i = 0; i <  neighbours_count; ++i ) {
            if ( recv_count[i] > 0 ) {
                MPI_Recv(&direc1[number_of_elements + partitions_offsets[i]], 
                         1, recv_datatypes[i], i, 10, MPI_COMM_WORLD, &statuses[i]);
            }
        }


        for ( i = 0; i <  neighbours_count; ++i ) {
            if ( recv_count[i] > 0 )
                MPI_Wait(&requests[i], &statuses[i]);
        }



        // compute new guess (approximation) for direc
        for ( nc = nintci; nc <= nintcf; nc++ ) {
            direc2[nc] = bp[nc] * direc1[nc] 
                         - bs[nc] * direc1[lcc[nc][0]]
                         - bw[nc] * direc1[lcc[nc][3]]
                         - bl[nc] * direc1[lcc[nc][4]]
                         - bn[nc] * direc1[lcc[nc][2]]
                         - be[nc] * direc1[lcc[nc][1]]
                         - bh[nc] * direc1[lcc[nc][5]];
        }
        /********** END COMP PHASE 1 **********/

        /********** START COMP PHASE 2 **********/
        // execute normalization steps
        double oc1, oc2, occ;
        double global_occ;
        if ( nor1 == 1 ) {
            oc1 = 0;
            occ = 0;

            for ( nc = nintci; nc <= nintcf; nc++ ) {
                occ = occ + adxor1[nc] * direc2[nc];
            }

            MPI_Allreduce(&occ, &global_occ, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);

            oc1 = global_occ / cnorm[1];
            for ( nc = nintci; nc <= nintcf; nc++ ) {
                direc2[nc] = direc2[nc] - oc1 * adxor1[nc];
                direc1[nc] = direc1[nc] - oc1 * dxor1[nc];
            }

            if1++;
        } else {
            if ( nor1 == 2 ) {
                oc1 = 0;
                occ = 0;

                for ( nc = nintci; nc <= nintcf; nc++ ) {
                    occ = occ + adxor1[nc] * direc2[nc];
                }

                MPI_Allreduce(&occ, &global_occ, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);

                oc1 = global_occ / cnorm[1];
                oc2 = 0;
                occ = 0;
                for ( nc = nintci; nc <= nintcf; nc++ ) {
                    occ = occ + adxor2[nc] * direc2[nc];
                }

                MPI_Allreduce(&occ, &global_occ, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);

                oc2 = global_occ / cnorm[2];
                for ( nc = nintci; nc <= nintcf; nc++ ) {
                    direc2[nc] = direc2[nc] - oc1 * adxor1[nc] - oc2 * adxor2[nc];
                    direc1[nc] = direc1[nc] - oc1 * dxor1[nc] - oc2 * dxor2[nc];
                }

                if2++;
            }
        }

        // compute the new residual
        cnorm[nor] = 0;
        double omega = 0;
        for ( nc = nintci; nc <= nintcf; nc++ ) {
            cnorm[nor] = cnorm[nor] + direc2[nc] * direc2[nc];
            omega = omega + resvec[nc] * direc2[nc];
        }
        

        MPI_Allreduce(MPI_IN_PLACE, &cnorm[nor], 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
        MPI_Allreduce(MPI_IN_PLACE, &omega, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);

        omega = omega / cnorm[nor];
        double res_updated = 0.0;
        for ( nc = nintci; nc <= nintcf; nc++ ) {
            var[nc] = var[nc] + omega * direc1[nc];
            resvec[nc] = resvec[nc] - omega * direc2[nc];
            res_updated = res_updated + resvec[nc] * resvec[nc];
        }
        

        MPI_Allreduce(MPI_IN_PLACE, &res_updated, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);

        res_updated = sqrt(res_updated);

        *residual_ratio = res_updated / resref;

        // exit on no improvements of residual
        if ( *residual_ratio <= 1.0e-10 ) break;

        iter++;

        // prepare additional arrays for the next iteration step
        if ( nor == nomax ) {
            nor = 1;
        } else {
            if ( nor == 1 ) {
                for ( nc = nintci; nc <= nintcf; nc++ ) {
                    dxor1[nc] = direc1[nc];
                    adxor1[nc] = direc2[nc];
                }
            } else {
                if ( nor == 2 ) {
                    for ( nc = nintci; nc <= nintcf; nc++ ) {
                        dxor2[nc] = direc1[nc];
                        adxor2[nc] = direc2[nc];
                    }
                }
            }

            nor++;
        }
        nor1 = nor - 1;
        /********** END COMP PHASE 2 **********/
    }

    free(resvec);
    free(direc1);
    free(direc2);
    free(adxor1);
    free(adxor2);
    free(dxor1);
    free(dxor2);

    return iter;
}


