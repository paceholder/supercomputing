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

int test_start()
{
    if ( PAPI_start_counters( Events, 2 ) != PAPI_OK )
        return -1;
    else 
        return 0;
}

int test_measure()
{
    if ( PAPI_read_counters( values, NUM_EVENTS ) != PAPI_OK )
        return -1;
    else {
        float rate = (float)values[0] / (float)(values[1]);
        printf("L1 %f\n", rate);
        return 0;
    }
}

void test_stop()
{

}

void test_write_to_file(const char* file_name)
{

}
