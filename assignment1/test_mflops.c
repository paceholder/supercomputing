#include <stdio.h>

#include <papi.h>

#include "test.h"

#define NUM_EVENTS 2
/* 
 * PAPI_L1_TCH  0x80000055  Level 1 total cache hits
 * PAPI_L2_TCH  0x80000056  Level 2 total cache hits
 * PAPI_L1_TCM  0x80000006  Level 1 cache misses
 * PAPI_L2_TCM  0x80000007  Level 2 cache misses
 */
static float rtime, ptime, mflops;
static long_long flpops;

/* output file */
static char* res_file_name = "pstats.dat";
static FILE* res_file;

int test_start()
{
    res_file = fopen(res_file_name, "w");
    if (res_file == NULL) {
        printf("Error opening file %s\n", res_file_name);
        return -1;
    }

    PAPI_flops (&rtime, &ptime, &flpops, &mflops);
    return 0;
}

int test_measure(char* phase)
{
    PAPI_flops (&rtime, &ptime, &flpops, &mflops);
    fprintf(res_file, "%s_Realtime=%f\n", phase, ptime);
    fprintf(res_file, "%s_Mflops=%f\n", phase, mflops);
    return 0;
}

void test_stop()
{
    fclose(res_file);
}

