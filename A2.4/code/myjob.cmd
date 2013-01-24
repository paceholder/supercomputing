#! /bin/bash

#SBATCH -o /home/hpc/h039u/h039uan/myjob.%j.%n.out

#SBATCH -J gccg

#SBATCH --clusters=mpp1

#SBATCH --partition=mpp1_batch

#SBATCH --get-user-env

#SBATCH --time=00:10:00

#SBATCH --mail-type=end
#SBATCH --mail-user=pinaev@in.tum.de

#SBATCH --ntasks=16

source /etc/profile.d/modules.sh

module load metis papi scorep cube png

export SCOREP_METRIC_PAPI="PAPI_TOT_CYC,PAPI_FP_INS"
export SCOREP_METRIC_RUSAGE="all"

for num in "2" "4" "8" "16"
do
    export SCOREP_EXPERIMENT_DIRECTORY="scp-pent-dual-"$num
    srun_ps -x -n $num ./gccg pent.geo.bin dual dual
done
