/**
 * Functions to test the data distribution and communication lists creation algorithms
 *
 * @date 22-Oct-2012
 * @author V. Petkov
 */
#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#include "test_functions.h"

#include "util_write_files.h"
#include "util_read_files.h"



int test_distribution(char *file_in, char *file_vtk_out, int *local_global_index, int num_elems,
                      double *cgup) {
    int nintci;
    int nintcf;
    int nextci;
    int nextcf;
    int** lcc;
    double* bs;
    double* be;
    double* bn;
    double* bw;
    double* bl;
    double* bh;
    double* bp;

    double* su;
    int points_count;
    int** points;
    int* elems;

    double* v = NULL;

    int f_status = read_binary_geo(file_in, &nintci, &nintcf, &nextci, &nextcf, &lcc,
                                   &bs, &be, &bn, &bw,
                                   &bl, &bh, &bp,
                                   &su, &points_count,
                                   &points, &elems);

    int my_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);    /// Get current process id

    vtk_write_unstr_grid_header(file_in, file_vtk_out, 0, nintcf, points_count, points, elems);

    v = (double*) calloc(nintcf+1, sizeof(double));

    int i;
    for ( i = 0; i <= num_elems; ++i ) {
        v[local_global_index[i]] = cgup[i];
    }


    vtk_append_double(file_vtk_out, "cgup", 0, nintcf, v);

    for ( i = 0; i <= num_elems; ++i ) {
        v[local_global_index[i]] = bp[i];
    }

    vtk_append_double(file_vtk_out, "bp", 0, nintcf, v);

    free(v);

    return 0;
}

int test_communication(char *file_in, char *file_vtk_out, int *local_global_index, int num_elems,
                       int* send_count, int** send_list, int* recv_count,
                       int** recv_list) {
    int nintci;
    int nintcf;
    int nextci;
    int nextcf;
    int** lcc;
    double* bs;
    double* be;
    double* bn;
    double* bw;
    double* bl;
    double* bh;
    double* bp;
    double* cgup;
    double* su;
    int points_count;
    int** points;
    int* elems;

    int f_status = read_binary_geo(file_in, &nintci, &nintcf, &nextci, &nextcf, &lcc,
                                   &bs, &be, &bn, &bw,
                                   &bl, &bh, &bp,
                                   &su, &points_count,
                                   &points, &elems);

    int my_rank;
    int num_procs;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);    /// Get current process id
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

    int* commlist = NULL;
    commlist = (int*) calloc((nintcf + 1), sizeof(int));
    int i;
    for ( i = 0; i < (nintcf +1); ++i )
        commlist[i] = 0;

    // 5 received
    // 10 send
    // 15 other cells

    int j;

    for ( i = 0; i <= num_elems; ++i ) {
        commlist[local_global_index[i]] = 15;
    }

    for ( i = 0; i < num_procs; ++i ) {
        for ( j = 0; j < send_count[i]; ++j ) {
            commlist[send_list[i][j]] = 10;
        }
        for ( j = 0; j < recv_count[i]; ++j ) {
            commlist[recv_list[i][j]] = 5;
        }
    }


    vtk_append_integer(file_vtk_out, "communication", 0, nintcf, commlist);

    free(commlist);

    return 0;
}

