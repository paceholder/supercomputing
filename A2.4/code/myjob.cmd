#! /bin/bash

#SBATCH -o /home/hpc/h039u/h039uan/myjob.%j.%n.out

#SBATCH -J gccg

#SBATCH --clusters=mpp1

#SBATCH --get-user-env

#SBATCH --time=00:10:00

#SBATCH --mail-type=end
#SBATCH --mail-user=pinaev@in.tum.de

#SBATCH --ntasks=64

source /etc/profile.d/modules.sh

module load metis papi scorep cube

export SCOREP_METRIC_PAPI=PAPI_TOT_CYC,PAPI_FP_INS
export SCOREP_METRIC_RUSAGE=all


./gccg ./pent.geo.bin dual dual
