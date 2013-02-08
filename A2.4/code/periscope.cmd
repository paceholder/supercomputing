#! /bin/bash

#SBATCH -o /home/hpc/h039u/h039uan/myjob.%j.%n.out

#SBATCH -J gccg

#SBATCH --clusters=mpp1

#SBATCH --partition=mpp1_batch

#SBATCH --get-user-env

#SBATCH --time=00:40:00

#SBATCH --mail-type=end
#SBATCH --mail-user=pinaev@in.tum.de

#SBATCH --ntasks=8

source /etc/profile.d/modules.sh

module unload mpi.intel
module load mpi.parastation
module load periscope/1.5 metis papi scorep cube png

export SCOREP_METRIC_PAPI=""
export SCOREP_METRIC_RUSAGE=""
export SCOREP_ENABLE_TRACING=""
export SCOREP_EXPERIMENT_DIRECTORY=""

for init in "1" "2" "3"
do
    make -f Makefile-instrumented clean
    make -f Makefile-instrumented "INST=$init"

    if [ $init == "1" ]; then
        ph = "--phase=OA_Init_Phase"
    fi

    if [ $init == "2" ]; then
        ph = "--phase=OA_Comp_Phase"
    fi

    if [ $init == "3" ]; then
        ph = "--phase=OA_Final_Phase"
    fi


    for dist in "classical" "dual"
    do
        for geom in "pent.geo.bin" "cojack.geo.bin"
        do
            #"64"
            for num in "4" "8"
            do
                psc_frontend --apprun="./gccg $geom $dist $dist" --mpinumprocs=$num --strategy=MPI --force-localhost $ph --propfile="properties-$geom-$dist-INIT$init-$num.psc"
            done
        done
    done
done
