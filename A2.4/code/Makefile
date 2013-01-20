####################################################################
#                                                                  #
#             Makefile for FIRE Solver Benchmarks                  #
#                                                                  #
####################################################################

CC = mpicc
CFLAGS = -Wall -O3 
LIBS = -lm

# LIBPOS=libpos.a
# AR = ar
# ARFLAGS = rv

SRCS = initialization.c compute_solution.c finalization.c util_read_files.c util_write_files.c test_functions.c gccg.c

all: gccg 

gccg: $(SRCS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS) $(METIS_LIB) $(METIS_INC)

clean:
	rm -rf *.o gccg
