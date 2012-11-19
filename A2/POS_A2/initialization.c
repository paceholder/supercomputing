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
                   int*** recv_list, long** epart, long** npart, long** objval) {
    /********** START INITIALIZATION **********/
    int i = 0;
    int j;
    int my_rank;
    int num_procs;
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);    /// Get current process id
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);    /// get number of processes
    
    if (my_rank == 0) {

        // read-in the input file
        int f_status = read_binary_geo(file_in, &*nintci, &*nintcf, &*nextci, &*nextcf, &*lcc, &*bs,
                                       &*be, &*bn, &*bw, &*bl, &*bh, &*bp, &*su, &*points_count,
                                       &*points, &*elems);

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
    } 

    //BS uses intervals
    // [NINTCI, NINTCF]
    // [NEXTCI, NEXTCF]

        /*
        METIS_PartMeshDual(ne, nn, eptr, eind, vwgt, vsize, ncommon, 
        nparts, tpwgts, options, objval, epart, npart)

        – ne, nn: number of elements and nodes in the mesh
        – eptr: array with start and end indices of the element‘s node IDs in eind
        – eind: array with the Ids of the nodes that compose all elements
        – vwgt, vsize: array with elements weights and sizes
        – ncommon: number of common nodes for 2 elements to become neighbors
        – nparts: number of partitions to generate
        – tpwgts: partition weight (can be used to fine-tune results to architectures)
        – options: METIS options array (always init with METIS_SetDefaultOptions)
        – [out] objval: resulting edgecut or total communication volume
        – [out] epart: resulting distribution of elements to partitions
        – [out] npart: resulting distribution of nodes to partitions
        */

    long ne = *nextcf+1;
    long nn = *points_count;

    long* eptr;
    eptr = (long*) malloc  (ne * sizeof(long));
    for(i = 0; i < ne; ++i)
        eptr[i] = i * 8;


    long* eind = (long*) malloc (ne * sizeof(long) * 8);
    for(i = 0; i < ne; ++i)
      for(j = 0; j < 8; ++j)
        eind[8*i + j] = *elems[8*i+j];


//    int objval;
  //  int* epart;
    //int* npart;

    *epart = (long*) malloc ((*nintcf + 1) * sizeof(long));
    *npart = (long*) malloc ((*points_count) * sizeof(long));

    long ncommon = 4;
    long procs = num_procs;
//  METIS_PartMeshDual(ne, nn,           eptr, eind,   vwgt, vsize, ncommon, nparts, tpwgts, options, objval, epart, npart)
//


    METIS_PartMeshDual(&ne, &nn, eptr, eind, NULL, NULL, &ncommon, 
                       (long*) &procs, NULL, NULL, 
                       *objval, *epart, *npart);

    printf("Number of volumes %lu\n", *objval);
    

    return 0;
}

