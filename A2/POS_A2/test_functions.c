/**
 * Functions to test the data distribution and communication lists creation algorithms
 *
 * @date 22-Oct-2012
 * @author V. Petkov
 */
#include <stdio.h>
#include <stdlib.h>

#include "test_functions.h"

#include "util_write_files.h"
#include "util_read_files.h"

#include "mpi.h"

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
    printf("PROC 3 rank %d\n", my_rank);

    vtk_write_unstr_grid_header(file_in, file_vtk_out, 0, nintcf, points_count, points, elems);

    printf("PROC 3 - (NINTCF+1) %d\n", nintcf+1);
    v = (double*) malloc( (size_t)(nintcf+1) * sizeof(double));
    printf("values %p\n", v);
    printf("values 0 %f\n", v[0]);

    printf("PROC 3 - before filling ARRAY\n");
    printf("PROC 3 - number of elements %d\n", num_elems);
    printf("PROC 3 - LAST ELEM %d\n", local_global_index[num_elems]);
    printf("PROC 3 - LAST ELEM cgup %f\n", cgup[num_elems]);

    int i; 
    for(i = 0; i <= num_elems; ++i) {
        v[local_global_index[i]] = cgup[i];
    }

    printf("PROC 3 - after ARRAY\n");

    vtk_append_double(file_vtk_out, "partition", 0, num_elems, v);
    // Return an error if not implemented
    return -1;
}

int test_communication(char *file_in, char *file_vtk_out, int *local_global_index, int *num_elems, 
                       int neighbors_count, int* send_count, int** send_list, int* recv_count, 
                       int** recv_list) {
    // Return an error if not implemented
    return -1;
}

