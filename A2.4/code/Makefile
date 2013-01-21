####################################################################
#                                                                  #
#             Makefile for FIRE Solver Benchmarks                  #
#                                                                  #
####################################################################

CC = scorep --user mpicc
CFLAGS = -Wall -O3 # -DDEBUG_OUTPUT

SRCS = initialization.c compute_solution.c \
       finalization.c util_read_files.c \
       util_write_files.c test_functions.c gccg.c

OBJS = $(SRCS:%.c=%.o)

all: gccg

%.o:%.c
	$(CC) $(CFLAGS) $(METIS_INC) -I$(SCOREP_INC) -c -o $@ $<

gccg: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(METIS_LIB)

clean:
	rm -rf *.o gccg
