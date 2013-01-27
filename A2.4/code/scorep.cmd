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

export SCOREP_METRIC_PAPI="PAPI_TOT_CYC,PAPI_FP_INS"
export SCOREP_METRIC_RUSAGE="all"

make -f Makefile-instrumented clean
make -f Makefile-instrumented

for dist in "classical" "dual"
do
    for geom in "pent.geo.bin" "cojack.geo.bin"
    do
        for num in "2" "4" "8" "16" "32" "64"
        do
            echo "scorep-$dist-$geom-$num"
            export SCOREP_EXPERIMENT_DIRECTORY="scorep-$num-$dist-$geom"
            srun_ps -x -n $num ./gccg $geom $dist $dist
        done
    done
done
