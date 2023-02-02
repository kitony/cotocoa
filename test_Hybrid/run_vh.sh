#!/bin/bash
#PBS -q SQUID
#PBS --group=K2206
#PBS -T necmpi
#PBS -l elapstim_req=0:05:00

#PBS -b 1
#PBS -l cpunum_job=18
#PBS -l memsz_job=100GB
 
cd $PBS_O_WORKDIR
module load BaseVEC

mpirun    -vh -n 9 ./requester_vh : -vh -n 1 ./coupler_vh : \
          -vh -n 4 ./worker_1_vh : -vh -n 4 ./worker_2_vh

