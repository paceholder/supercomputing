CC = icc
CFLAGS = -g -O3 -c99 -opt-prefetch=4
LIBS = -lm

# Make sure you have loaded the papi module before uncommenting 
# these and include papi.h in the sources
CFLAGS += $(PAPI_INC)
LIBS += $(PAPI_LIB)

SRCS = xread.c xwrite.c gccg.c vol2mesh.c test.c
OBJS =  $(addsuffix .o, $(basename $(SRCS)))

SRCS2 = binconv.c
OBJS2 =  $(addsuffix .o, $(basename $(SRCS2)))

all: gccg binconv

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

gccg: $(OBJS) 
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

binconv: $(OBJS2)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -rf *.o gccg binconv
