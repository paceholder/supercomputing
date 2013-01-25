#! /bin/bash

#SBATCH -o /home/hpc/h039u/h039uan/myjob.%j.%n.out

#SBATCH -J gccg

#SBATCH --clusters=mpp1

#SBATCH --partition=mpp1_batch

#SBATCH --get-user-env

#SBATCH --time=00:10:00

#SBATCH --mail-type=end
#SBATCH --mail-user=pinaev@in.tum.de

#SBATCH --ntasks=64

source /etc/profile.d/modules.sh

module load metis papi scorep cube png

make -f Makefile-speedup clean
make -f Makefile-speedup

for geom in "pent.geo.bin" "cojack.geo.bin"
do
    srun_ps -x -n 1 ../../serial/gccg $geom dist dist
done

for dist in "classical" "dual"
do
    for geom in "pent.geo.bin" "cojack.geo.bin"
    do
        for num in "2" "4" "8" "16" "32" "64"
        do
            echo "----------------"$dist"   "$geom"    "$num
            srun_ps -x -n $num ./gccg $geom $dist $dist > $geom"-"$dist"-"$num".txt"
        done
    done
done
