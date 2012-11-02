#include <stdio.h>

#include <papi.h>

#include "test.h"

#define NUM_EVENTS 2
static int Events[NUM_EVENTS] = { PAPI_FP_INS, PAPI_TOT_CYC };
static long_long values[NUM_EVENTS];

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


    if ( PAPI_start_counters( Events, 2 ) != PAPI_OK )
        return -1;
    else 
        return 0;
}

int test_measure(char* phase)
{
    if ( PAPI_read_counters( values, NUM_EVENTS ) != PAPI_OK )
        return -1;
    else {
        float rate = (float)values[0] / (float)(values[1]);
        fprintf(res_file, "%s_PAPI_FP_INS=%lld\n", phase, values[0]);
        fprintf(res_file, "%s_PAPI_TOT_CYC=%lld\n", phase, values[1]);

        return 0;
    }
}

void test_stop()
{
    fclose(res_file);
}

