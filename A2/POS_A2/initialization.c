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
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);    /// Get current process id
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);    /// get number of processes
    
    printf("hello from process %d\n", my_rank);

    if (my_rank == 0) {

        printf("Before reading the files %d\n", my_rank);

        // read-in the input file
        int f_status = read_binary_geo(file_in, &*nintci, &*nintcf, &*nextci, &*nextcf, &*lcc, &*bs,
                                       &*be, &*bn, &*bw, &*bl, &*bh, &*bp, &*su, &*points_count,
                                       &*points, elems);

        printf("Reading the files %d\n", my_rank);
        printf("nintcf %d\n", *nintcf);
        printf("nextcf %d\n", *nextcf);
        printf("points count %d\n", *points_count);
        

        if ( f_status != 0 ) return f_status;

        *var = (double*) calloc(sizeof(double), (*nextcf + 1));
        *cgup = (double*) calloc(sizeof(double), (*nextcf + 1));
        *oc = (double*) calloc(sizeof(double), (*nintcf + 1));
        *cnorm = (double*) calloc(sizeof(double), (*nintcf + 1));

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

        
        printf("Arrays intialized %d\n", my_rank);


        idx_t options[METIS_NOPTIONS];

    idx_t ne = *nintcf+1;
    idx_t nn = *points_count;

    idx_t* eptr = (idx_t*) malloc  ((ne + 1) * sizeof(idx_t));
    for(i = 0; i < ne + 1; ++i)
        eptr[i] = i * 8;


    printf("FUCK YOU first time\n");
    idx_t* eind = (idx_t*) malloc (ne * sizeof(idx_t) * 8);

    for(i = 0; i < ne * 8; ++i)
        eind[i] = (*elems)[i];

    idx_t *ept = (idx_t*) malloc (ne * sizeof(idx_t));
    idx_t *npt = (idx_t*) malloc (nn * sizeof(idx_t));  

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


    return 0;
}

