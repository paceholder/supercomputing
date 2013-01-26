

files = ["cojack.geo.bin", "pent.geo.bin"]
nums = [2,4,8,16,32,64]
dist = ["dual", "classical"]


for d in dist:
    print "====================================="
    for f in files:
        print "====================================="
        inits = []
        computes = []
        finals = []
        print f + "-" + d
        if f.startswith("cojack"):
            inits = [0.27]
            computes = [20.67]
            finals = [22.23]
        else:
            inits = [0.23]
            computes = [4.8]
            finals = [5.27]
        for n in nums:
            filename = f + "-" + d + "-" + str(n) + ".txt"

            fi = open(filename, "r")
            for l in fi.readlines():
                if l.startswith("init"):
                   s = l.split("=")
                   inits.append(float(s[-1].strip()))
                if l.startswith("compute"):
                   s = l.split("=")
                   computes.append(float(s[-1].strip()))
                if l.startswith("final"):
                   s = l.split("=")
                   finals.append(float(s[-1].strip()))

        for i in range(len(finals)):
            finals[i] -= computes[i]
            computes[i] -= inits[i]


        ll = lambda s: str(s)+"\t"
        pp = lambda x, y: x+ y


        print reduce(pp, map(ll, inits))
        print reduce(pp, map(ll, computes))
        print reduce(pp, map(ll, finals))

