import subprocess

#geometry_files = ["./cojack.dat", "./drall.dat", "/pent.dat", "./tjunc.dat"]
geometry_files = ["./drall.dat"]

optimization_flags = [ "-O0", "-O1", "-O2", "-O3", "-O3 -opt-prefetch=2", "-O3 -opt-prefetch=4"]

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

iterations=2

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

        for geometry in geometry_files:
            print "\t\t SCENARIO:", geometry
            for i in range(iterations):
                print "\t\tRUN: ", i
                subprocess.call(["srun_ps", "./gccg", "text", geometry, "out.txt"])

                subprocess.call(["cp", "pstats.dat", "%s_%s_%d_%d" % (test, geometry[2:],j,i)])


f = open("result", "w")
for geometry in geometry_files:
    f.write("\t\t GEOMETRY %s\n\n" % geometry)

    for j in range(len(optimization_flags)):
        flags = optimization_flags[j]

        f.write("\t\t FLAG %s\n\n" % flags)

        #   for test in test_variants:
        test = test_variants[0] # l1

        results = [0, 0, 0.0] * 3;
        for i in range(iterations):
            ff = open("%s_%s_%d_%d" % (test, geometry[2:],j,i), "r")
            line = ff.readline()
            line = line.strip()
            line = line.split("=")
            results[0] += int(line[1])

            line = ff.readline()
            line = line.strip()
            line = line.split("=")
            results[1] += int(line[1])

            line = ff.readline()
            line = line.strip()
            line = line.split("=")
            results[2] += float(line[1][:-2])

            line = ff.readline()
            line = line.strip()
            line = line.split("=")
            results[3] += int(line[1])

            line = ff.readline()
            line = line.strip()
            line = line.split("=")
            results[4] += int(line[1])

            line = ff.readline()
            line = line.strip()
            line = line.split("=")
            results[5] += float(line[1][:-2])

            line = ff.readline()
            line = line.strip()
            line = line.split("=")
            results[6] += int(line[1])

            line = ff.readline()
            line = line.strip()
            line = line.split("=")
            results[7] += int(line[1])

            line = ff.readline()
            line = line.strip()
            line = line.split("=")
            results[8] += float(line[1][:-2])
            ff.close()
            subprocess.call(["rm", "%s_%s_%d_%d" % (test, geometry[2:],j,i)])


        results = [r/float(iterations) for r in results]

        f.write("INIT\n")
        f.write("L1miss %f\n" % results[0])
        f.write("L1tot %f\n" % results[1])
        f.write("L1rate %f\n" % results[2])
        f.write("CALC\n")
        f.write("L1miss %f\n" % results[3])
        f.write("L1tot %f\n" % results[4])
        f.write("L1rate %f\n" % results[5])
        f.write("OUT\n")
        f.write("L1miss %f\n" % results[6])
        f.write("L1tot %f\n" % results[7])
        f.write("L1rate %f\n" % results[8])


        #   for test in test_variants:
        test = test_variants[1] # l1

        results = [0, 0, 0.0] * 3;
        for i in range(iterations):
            ff = open("%s_%s_%d_%d" % (test, geometry[2:],j,i), "r")
            line = ff.readline()
            line = line.strip()
            line = line.split("=")
            results[0] += int(line[1])

            line = ff.readline()
            line = line.strip()
            line = line.split("=")
            results[1] += int(line[1])

            line = ff.readline()
            line = line.strip()
            line = line.split("=")
            results[2] += float(line[1][:-2])

            line = ff.readline()
            line = line.strip()
            line = line.split("=")
            results[3] += int(line[1])

            line = ff.readline()
            line = line.strip()
            line = line.split("=")
            results[4] += int(line[1])

            line = ff.readline()
            line = line.strip()
            line = line.split("=")
            results[5] += float(line[1][:-2])

            line = ff.readline()
            line = line.strip()
            line = line.split("=")
            results[6] += int(line[1])

            line = ff.readline()
            line = line.strip()
            line = line.split("=")
            results[7] += int(line[1])

            line = ff.readline()
            line = line.strip()
            line = line.split("=")
            results[8] += float(line[1][:-2])
            ff.close()
            subprocess.call(["rm", "%s_%s_%d_%d" % (test, geometry[2:],j,i)])

        results = [r/float(iterations) for r in results]

        f.write("INIT\n")
        f.write("L2miss %f\n" % results[0])
        f.write("L2tot %f\n" % results[1])
        f.write("L2rate %f\n" % results[2])
        f.write("CALC\n")
        f.write("L2miss %f\n" % results[3])
        f.write("L2tot %f\n" % results[4])
        f.write("L2rate %f\n" % results[5])
        f.write("OUT\n")
        f.write("L2miss %f\n" % results[6])
        f.write("L2tot %f\n" % results[7])
        f.write("L2rate %f\n" % results[8])



        #   for test in test_variants:
        test = test_variants[2] # l1

        results = [0.0, 0.0] * 3;
        for i in range(iterations):
            ff = open("%s_%s_%d_%d" % (test, geometry[2:],j,i), "r")
            line = ff.readline()
            line = line.strip()
            line = line.split("=")
            results[0] += float(line[1])

            line = ff.readline()
            line = line.strip()
            line = line.split("=")
            results[1] += float(line[1])

            line = ff.readline()
            line = line.strip()
            line = line.split("=")
            results[2] += float(line[1])

            line = ff.readline()
            line = line.strip()
            line = line.split("=")
            results[3] += float(line[1])

            line = ff.readline()
            line = line.strip()
            line = line.split("=")
            results[4] += float(line[1])

            line = ff.readline()
            line = line.strip()
            line = line.split("=")
            results[5] += float(line[1])
            ff.close()
            subprocess.call(["rm", "%s_%s_%d_%d" % (test, geometry[2:],j,i)])


        results = [r/float(iterations) for r in results]

        f.write("INIT\n")
        f.write("realtime %f\n" % results[0])
        f.write("mflops %f\n" % results[1])
        f.write("CALC\n")
        f.write("realtime %f\n" % results[2])
        f.write("mflops %f\n" % results[3])
        f.write("OUT\n")
        f.write("realtime %f\n" % results[4])
        f.write("mflops %f\n" % results[5])


f.close()






