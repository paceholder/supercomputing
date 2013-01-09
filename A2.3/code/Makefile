####################################################################
#                                                                  #
#             Makefile for FIRE Solver Benchmarks                  #
#                                                                  #
####################################################################

CC = mpiicc
CFLAGS = -Wall -g -O0 
LIBS = -lm

LIBPOS=libpos.a
AR = ar
ARFLAGS = rv

SRCS = initialization.c compute_solution.c finalization.c util_read_files.c util_write_files.c test_functions.c
OBJS =  $(addsuffix .o, $(basename $(SRCS)))

all: gccg 

%.o: %.c $(DEPS)
	$(CC) -c -o  $@ $< $(CFLAGS) $(METIS_INC) 

gccg: gccg.c $(LIBPOS)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS) $(METIS_LIB) $(METIS_INC)

$(LIBPOS) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $+

clean:
	rm -rf *.o gccg $(LIBPOS)
