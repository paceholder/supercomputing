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

module load periscope/1.5 metis papi scorep cube png



for init in "1" "2" "3"
do
    make -f Makefile-instrumented clean
    make -f Makefile-instrumented "INIT=$init"

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
            for num in "2" "4" "8" "16" "32" "64"
            do
                psc_frontend --apprun="./gccg $geom $dist $dist" --mpinumprocs=$num --strategy=MPI --force-localhost $ph --profile="properties-$geom-$dist-INIT$init-$num.psc > $geom.$dist.$num-periscope.txt
            done
        done
    done
done
