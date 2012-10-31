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

print main_file_variants
for test in test_variants:
    print "\t\t MAINFILE", mainfile

    subprocess.call(["rm", "./test.c"])
    subprocess.call(["cp", test, "./test.c"])


    for flags in optimization_flags:
        # compile the program  - 3 vesions

        print "\t\t FLAG", flags
        #create Makefile
        f = open("Makefile", "w")
        f.write(makefile_body1 % flags)
        f.write(makefile_body2)
        f.close()

        subprocess.call(["make", "clean"])
        subprocess.call(["make"])

        for test in test_files:
            print "\t\t SCENARIO:", test
            for i in range(3):
                print "\t\tRUN: ", i
                subprocess.call(["./gccg", test, "out.txt"])



