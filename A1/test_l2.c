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
static int Events[NUM_EVENTS] = { PAPI_L2_TCM, PAPI_L2_TCA};
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
        fprintf(res_file, "%s_PAPI_L2_TCM=%lld\n", phase, values[0]);
        fprintf(res_file, "%s_PAPI_L2_TCA=%lld\n", phase, values[1]);
        fprintf(res_file, "%s_L2MissRate=%f%%\n",  phase, (rate * 100.0));

        return 0;
    }
}

void test_stop()
{
    fclose(res_file);
}

