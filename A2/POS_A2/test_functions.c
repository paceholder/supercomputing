/**
 * Functions to test the data distribution and communication lists creation algorithms
 *
 * @date 22-Oct-2012
 * @author V. Petkov
 */

#include "util_write_files.h"
#include "util_read_files.h"

int test_distribution(char *file_in, char *file_vtk_out, int *local_global_index, int num_elems, 
                      double *cgup) {

    int nintci;
    int nintcf;
    int nextci;
    int nextcf,
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

    int f_status = read_binary_geo(file_in, &nintci, &nintcf, &nextci, &nextcf, &lcc,
                                    &bs, &be, &bn, &bw, 
                                    &bl, &bh, &bp, 
                                    &su, &points_count,
                                    &points, &elems);


    vtk_write_unstr_grid_header(file_in, file_vtk_out, nintcf, nintcf, points_count, points, elems); 

    double* values = (double*) malloc((nextcf+1) * sizeof(double));

    memset (values, 0.0, (nextcf+1) * sizeof(double));

    int i;
    for(i = 0; i <= num_elems; ++i) {
        values[local_global_index[i]] = cgup[i];
    }

    vtk_append_double(file_vtk_out, "partition", 0, num_elems, cgup);
    // Return an error if not implemented
    return -1;
}

int test_communication(char *file_in, char *file_vtk_out, int *local_global_index, int *num_elems, 
                       int neighbors_count, int* send_count, int** send_list, int* recv_count, 
                       int** recv_list) {
    // Return an error if not implemented
    return -1;
}

