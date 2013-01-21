/**
 * Main GCCG program
 *
 * @author E. Xue, V. Petkov
 * @date 22-May-2009, 22-Oct-2012
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "mpi.h"

#ifdef INSTRUMENTED
    #include <scorep/SCOREP_User.h>
#endif

#include "initialization.h"
#include "compute_solution.h"
#include "finalization.h"
#include "test_functions.h"

int main(int argc, char *argv[]) {
    int my_rank, num_procs;

    const int max_iters = 10000;    /// maximum number of iteration to perform

    /** Simulation parameters parsed from the input datasets */
    int nintci, nintcf;    /// internal cells start and end index
    /// external cells start and end index. The external cells are only ghost cells.
    /// They are accessed only through internal cells
    int nextci, nextcf;
    int **lcc;    /// link cell-to-cell array - stores neighboring information
    /// Boundary coefficients for each volume cell (South, East, North, West, High, Low)
    double *bs, *be, *bn, *bw, *bl, *bh;

    double *bp;    /// Pole coefficient
    double *su;    /// Source values

    double *var;    /// the variation vector -> keeps the result in the end

    /** Additional vectors required for the computation */
    double *cgup, *oc, *cnorm;

    double residual_ratio;    /// the ratio between the reference and the current residual


    /** Geometry data */
    int points_count;    /// total number of points that define the geometry
    int** points;    /// coordinates of the points that define the cells - size [points_cnt][3]
    int* elems;    /// definition of the cells using their nodes (points) - each cell has 8 points

    /** Mapping between local and remote cell indices */
    int* local_global_index;    /// local to global index mapping
    int* global_local_index;    /// global to local index mapping

    /** Lists of cells requires for the communication */
    int* send_count;    /// number of elements to send to each neighbor (size: neighbors_count)
    /// send lists for the other neighbors(cell ids which should be sent)(size:[#neighbors][#cells]
    int** send_list;
    int* recv_count;    /// how many elements are in the recv lists for each neighbor
    int** recv_list;    /// send lists for the other neighbor (see send_list)

    /** Metis Results */
    idx_t* epart;     /// partition vector for the elements of the mesh
    idx_t* npart;     /// partition vector for the points (nodes) of the mesh
    int objval;    /// resulting edgecut of total communication volume (classical distrib->zeros)

    int number_of_elements; // number of elements in current partition
    int *number_of_elements_in_partitions; // number of elements in all communicating partitions
    int *partitions_offsets; // offsets for direc1 vector

    MPI_Init(&argc, &argv);    /// Start MPI
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);    /// Get current process id
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);    /// get number of processes

    if ( argc < 3 ) {
        fprintf(stderr, "Usage: ./gccg <input_file> <output_prefix> <partition_type>\n");
        MPI_Abort(MPI_COMM_WORLD, -1);
    }

    char *file_in = argv[1];
    char *out_prefix = argv[2];
    char *part_type = (argc == 3 ? "classical" : argv[3]);

    /********** START INITIALIZATION **********/

#ifdef INSTRUMENTED
    SCOREP_USER_REGION_DEFINE( init )
    SCOREP_USER_REGION_BEGIN( init, "init", SCOREP_USER_REGION_TYPE_PHASE )
#endif

    int init_status = initialization(file_in, part_type, &nintci, &nintcf, &nextci, &nextcf, &lcc,
                                     &bs, &be, &bn, &bw, &bl, &bh, &bp, &su, &points_count, &points,
                                     &elems, &var, &cgup, &oc, &cnorm, 
                                     &local_global_index,
                                     &global_local_index, 

                                     &number_of_elements,
                                     &number_of_elements_in_partitions,
                                     &partitions_offsets,

                                     &send_count, &send_list,
                                     &recv_count, &recv_list, 
                                     &epart, &npart, 
                                     &objval);
    if ( init_status != 0 ) {
        fprintf(stderr, "Failed to initialize data!\n");
        MPI_Abort(MPI_COMM_WORLD, my_rank);
    }


    #ifdef DEBUG_OUTPUT
    if ( my_rank == 2 ) {
        char file_vtk_out[1000];
        file_vtk_out[0] = '\0';
        strcat(file_vtk_out, out_prefix);
        strcat(file_vtk_out, "_");
        strcat(file_vtk_out, file_in);
        strcat(file_vtk_out, ".vtk");

        test_distribution(file_in, file_vtk_out, local_global_index, nintcf, cgup);

        test_communication(file_in, file_vtk_out, local_global_index, nintcf,
                           send_count, send_list, 
                           recv_count, recv_list);
    }
    #endif

    /********** END INITIALIZATION **********/



    /********** START COMPUTATIONAL LOOP **********/


#ifdef INSTRUMENTED
    SCOREP_USER_REGION_DEFINE( compute )
    SCOREP_USER_REGION_BEGIN( compute, "compute", SCOREP_USER_REGION_TYPE_PHASE )
#endif

    int total_iters = compute_solution(max_iters, nintci, nintcf, nextcf, lcc, 
                                       bp, bs, bw, bl, bn, be, bh, 
                                       cnorm, var, su, cgup, &residual_ratio,
                                       local_global_index, global_local_index, 

                                       number_of_elements,
                                       number_of_elements_in_partitions,
                                       partitions_offsets,

                                       send_count, send_list, 
                                       recv_count, recv_list);


#ifdef INSTRUMENTED
    SCOREP_USER_REGION_END( compute )
#endif

    /********** END COMPUTATIONAL LOOP **********/

    printf("AFTER COMPUTE SOLUTION\n");



    /********** START FINALIZATION **********/


#ifdef INSTRUMENTED
    SCOREP_USER_REGION_DEFINE( final )
    SCOREP_USER_REGION_BEGIN( final, "final", SCOREP_USER_REGION_TYPE_PHASE )
#endif

    finalization(file_in, out_prefix, total_iters, residual_ratio, nintci, nintcf, points_count,
                 points, elems, var, cgup, su);

#ifdef INSTRUMENTED
    SCOREP_USER_REGION_END( final )
#endif

    /********** END FINALIZATION **********/


    free(cnorm);
    free(oc);
    free(var);
    free(cgup);
    free(su);
    free(bp);
    free(bh);
    free(bl);
    free(bw);
    free(bn);
    free(be);
    free(bs);
    free(elems);

    
    int i;
    for(i = 0; i < nintcf + 1; i++) {
        free(lcc[i]);
    }
    free(lcc);

    for(i = 0; i < points_count; i++) {
        free(points[i]);
    }
    free(points);
    

    MPI_Finalize();    /// Cleanup MPI

    return 0;
}

