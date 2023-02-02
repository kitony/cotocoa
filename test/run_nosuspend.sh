#!/bin/bash
#PBS -q SQUID
#PBS --group=K2206
#PBS -T necmpi
#PBS -b 2
#PBS -l elapstim_req=0:05:00
#PBS -l memsz_job=10GB
#PBS -l vememsz_lhost=48GB
#PBS --venum-lhost=8
#PBS --use-hca=1

cd $PBS_O_WORKDIR
module load BaseVEC

mpirun -ve 0 -n 9 ./requester_nosuspend : -ve 0 -n 1 ./coupler_nosuspend : -ve 1 -n 4 ./worker_nosuspend_1 : -ve 1 -n 4 ./worker_nosuspend_2
