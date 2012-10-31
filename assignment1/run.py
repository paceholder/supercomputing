import subprocess

test_files = ["./cojack.dat", "./drall.dat", "/pent.dat", "./tjunc.dat"]


optimization_flags = ["-g", "-O0", "-O1", "-O2", "-O3", "-O3 -opt-prefetch=4"]

test_variants = ["./test_l1.c", "./test_l2.c", "./test_mflops.c"]

makefile_body1= \
"""
CC = icc
CFLAGS = %s -c99
#-g -c99
LIBS = -lm
"""

makefile_body2 = \
r"""
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
"""

iterations=5

for test in test_variants:
    print "\t\t TEST", test

    subprocess.call(["rm", "./test.c"])
    subprocess.call(["cp", test, "./test.c"])


    for j in range(len(optimization_flags)):
        flags = optimization_flags[j]
        # compile the program  - 3 vesions

        print "\t\t FLAG", flags
        #create Makefile
        f = open("Makefile", "w")
        f.write(makefile_body1 % flags)
        f.write(makefile_body2)
        f.close()

        subprocess.call(["make", "clean"])
        subprocess.call(["make"])

        for test_file in test_files:
            print "\t\t SCENARIO:", test_file
            for i in range(iterations):
                print "\t\tRUN: ", i
                subprocess.call(["./gccg", "text", test_file, "out.txt"])

                subprocess.call(["cp", "pstats.dat", "%s_%s_%d_%d" % (test, test_file[2:],j,i)])

