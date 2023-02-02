#!/bin/bash
#PBS -q MIX
#PBS --group=K2206
#PBS -T necmpi
#PBS -l elapstim_req=0:01:00

#PBS --job-separator
#PBS -b 1
#PBS -l cpunum_job=10
#PBS -l memsz_job=50GB

#PBS --job-separator
#PBS --venode=1
#PBS -l cpunum_job=1
#PBS -l memsz_job=10GB
#PBS -l vememsz_prc=5GB
 
cd $PBS_O_WORKDIR
module load BaseVEC

mpirun    -host 0 -vh -n 9 ./requester_nosuspend_vh : -host 0 -vh -n 1 ./coupler_nosuspend_vh : \
          -host 1 -vh -n 4 ./worker_nosuspend_1_vh : -host 1 -ve 0 -n 4 ./worker_nosuspend_2_ve

