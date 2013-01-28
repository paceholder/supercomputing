/*
 * compute_solution.h
 *
 *  Created on: Oct 21, 2012
 *      Author: petkovve
 */

#ifndef COMPUTE_SOLUTION_H_
#define COMPUTE_SOLUTION_H_

#include <metis.h>

int compute_solution(const int max_iters, 
                     int nintci, int nintcf, 
                     int** lcc, 
                     double* bp, 
                     double* bs, double* bw, double* bl, 
                     double* bn, double* be, double* bh,
                     double* cnorm, double* var, double *su, double* cgup, double* residual_ratio,
                     int* local_global_index, int* global_local_index,

                     int number_of_elements,
                     int* number_of_elements_in_partitions,
                     int* partitions_offsets,

                     int* send_count, int** send_list, 
                     int* recv_count, int** recv_list,
                     idx_t* epart);

#endif /* COMPUTE_SOLUTION_H_ */

