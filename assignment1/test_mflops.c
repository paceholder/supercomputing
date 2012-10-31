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

int test_start()
{
    PAPI_flops (&rtime, &ptime, &flpops, &mflops);
    return 0;
}

int test_measure()
{
    PAPI_flops (&rtime, &ptime, &flpops, &mflops);
    printf("realtime %f mflops %f\n", rtime, mflops);
    return 0;
}

void test_stop()
{

}

void test_write_to_file(const char* file_name)
{

}
