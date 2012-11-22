/**
 * Initialization step - parse the input file, compute data distribution, initialize LOCAL computational arrays
 *
 * @date 22-Oct-2012
 * @author V. Petkov
 */

#include <stdlib.h>
#include <mpi.h>
#include "metis.h"

#include "util_read_files.h"
#include "initialization.h"

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

    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);    /// Get current process id
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);    /// get number of processes
    

    if (my_rank == 0) {

        printf("Before reading the files %d\n", my_rank);

        // read-in the input file
        int f_status = read_binary_geo(file_in, &*nintci, &*nintcf, &*nextci, &*nextcf, &*lcc, &*bs,
                                       &*be, &*bn, &*bw, &*bl, &*bh, &*bp, &*su, &*points_count,
                                       &*points, elems);

        printf("Reading the files %d\n", my_rank);

        if ( f_status != 0 ) return f_status;

        glob_var = (double*) calloc(sizeof(double), (*nextcf + 1));
        glob_cgup = (double*) calloc(sizeof(double), (*nextcf + 1));
        glob_oc = (double*) calloc(sizeof(double), (*nintcf + 1));
        glob_cnorm = (double*) calloc(sizeof(double), (*nintcf + 1));

        // initialize the arrays
        for ( i = 0; i <= 10; i++ ) {
            (*oc)[i] = 0.0;
            (*cnorm)[i] = 1.0;
        }

        for ( i = (*nintci); i <= (*nintcf); i++ ) {
            (*cgup)[i] = 0.0;
            (*var)[i] = 0.0;
        }

        for ( i = (*nextci); i <= (*nextcf); i++ ) {
            (*var)[i] = 0.0;
            (*cgup)[i] = 0.0;
            (*bs)[i] = 0.0;
            (*be)[i] = 0.0;
            (*bn)[i] = 0.0;
            (*bw)[i] = 0.0;
            (*bl)[i] = 0.0;
            (*bh)[i] = 0.0;
        }

        for ( i = (*nintci); i <= (*nintcf); i++ )
            (*cgup)[i] = 1.0 / ((*bp)[i]);


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
            METIS_PartMeshDual(&ne, &nn, 
                            eptr, eind, 
                            NULL, NULL, &ncommon, 
                            &procs, NULL, options, 
                            &obvl, ept, npt);
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


        printf("Number of volumes %lu\n", obvl);
        printf("----------------------------------------\n");
    }


    printf("hello from process %d\n", my_rank);
//    #if IDXTYPEWIDTH=64
//
    // distribute lengths of METIS arrays
    MPI_Bcast(&ne, 1, MPI_LONG, 0, MPI_COMM_WORLD);
    MPI_Bcast(&nn, 1, MPI_LONG, 0, MPI_COMM_WORLD);

    printf("FUCK YOU first time\n");
    printf("%d - ne: %lu\n;", my_rank, ne);

    if (my_rank != 0) {
        ept = (idx_t*) malloc (ne * sizeof(idx_t));
        npt = (idx_t*) malloc (nn * sizeof(idx_t));
        printf("ALLOCATE %d\n", my_rank);
    }

    printf("FUCK YOU second time\n");
    printf("%d - nn: %lu\n;", my_rank, nn);

    // distribute METIS arrays
    MPI_Bcast(ept, ne, MPI_LONG, 0, MPI_COMM_WORLD);
    MPI_Bcast(npt, nn, MPI_LONG, 0, MPI_COMM_WORLD);

    MPI_Barrier(MPI_COMM_WORLD);

    printf("FUCK YOU THIRD time\n");

    // each node counts how many elements it must have
    int number_of_elements_per_node = 0;
    for(i = 0; i < ne; ++i)
        if (ept[i] == my_rank)
            ++number_of_elements_per_node;

    printf("Node %d has %d elements\n", my_rank, number_of_elements_per_node);

    *cgup = (double*) calloc(sizeof(double), number_of_elements_per_node);
    *local_global_index = (int*) calloc(sizeof(int), number_of_elements_per_node); // map local to global

    int next_elem = 0;
    for(i = 0; i < ne; ++i) {
        if (ept[i] == my_rank) {
            local_global_index[next_elem] = i;
            ++next_elem;
        }
    }


    for(i = 0; i < number_of_elements_per_node; ++i)
        cgup[i] = glob_cgup[local_global_index[i]];


    return 0;
}

