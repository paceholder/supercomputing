
from pylab import *

files = ["cojack.geo.bin", "pent.geo.bin"]
nums = [2,4,8,16,32,64]
dist = ["dual", "classical"]


for d in dist:
    print "====================================="
    clf()
    for fn in files:
        print "====================================="
        inits = []
        computes = []
        finals = []
        print fn + "-" + d
        if fn.startswith("cojack"):
            inits = [0.27]
            computes = [20.67]
            finals = [22.23]
        else:
            inits = [0.23]
            computes = [4.8]
            finals = [5.27]
        for n in nums:
            filename = fn + "-" + d + "-" + str(n) + ".txt"

            fi = open("./results/"+filename, "r")
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

        for i in range(len(inits)):
            #finals[i] -= computes[i]
            computes[i] -= inits[i]

        speedup = []
        for i in range(1,len(inits)):
            speedup.append( computes[0] / computes[i])


        
        if fn.startswith("coj"):
            subplot(211)
        else:
            subplot(212)
        plot(nums, speedup, 'or-', markersize=5)
        grid(True)
        xlabel('# procs')
        ylabel('speedup')
        xticks(nums)
        subplots_adjust(hspace = 0.6)
        title(fn)

        ll = lambda s: str(s)+"\t"
        pp = lambda x, y: x+ y


        print reduce(pp, map(ll, inits))
        print reduce(pp, map(ll, computes))
        print reduce(pp, map(ll, finals))

    savefig("../report/images/speedup"+d+".eps")
#    show()
