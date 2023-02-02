#!/bin/bash
#PBS -q SQUID
#PBS --group=K2206
#PBS -T necmpi
#PBS -l elapstim_req=0:03:00

#PBS -b 2
#PBS -l cpunum_job=24
#PBS -l memsz_job=128GB
 
cd $PBS_O_WORKDIR
module load BaseVEC

mpirun    -host 0 -vh -n 9 ./requester_H : -host 0 -vh -n 1 ./coupler_H : \
          -host 1 -vh -n 4 ./worker_1_H
