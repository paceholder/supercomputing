#! /bin/bash

#SBATCH -o /home/hpc/h039u/h039uan/myjob.%j.%n.out

#SBATCH -D /home/hpc/h039u/h039uan/supercomputing/A2.4/code

#SBATCH -J gccg

#SBATCH --clusters=mpp1

#SBATCH --get-user-env

#SBATCH --time=00:10:00

#SBATCH --mail-type=end
#SBATCH --mail-user=pinaev@in.tum.de

source /etc/profile.d/modules.sh

module load metis papi scorep cube

export SCOREP_METRIC_PAPI=PAPI_TOT_CYC,PAPI_FP_INS
export SCOREP_METRIC_RUSAGE=ru_utime,ru_stime,ru_maxrss,ru_ixrss,ru_idrss,ru_isrss,ru_minflt,ru_majflt,ru_nswap,ru_inblock,ru_outblock,ru_msgsnd,ru_msgrsv,ru_signals,ru_nvcsw,ru_nivcsw

#SBATCH --ntasks=4

./gccg ./pent.geo.bin dual dual
