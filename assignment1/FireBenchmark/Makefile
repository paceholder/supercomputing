
CC = icc
CFLAGS = -g -O0 -c99
#-g -c99
LIBS = -lm

# Make sure you have loaded the papi module before uncommenting 
# these and include papi.h in the sources
CFLAGS += $(PAPI_INC)
LIBS += $(PAPI_LIB)

SRCS = xread.c xwrite.c gccg.c vol2mesh.c
OBJS =  $(addsuffix .o, $(basename $(SRCS)))

all: gccg 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

gccg: $(OBJS) 
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	rm -rf *.o gccg 
