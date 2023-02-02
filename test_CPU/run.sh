#!/bin/sh
#PBS -q SQUID
#PBS --group=K2206
#PBS -T intmpi
#PBS -l elapstim_req=0:01:00

#PBS -b 1
#PBS -l memsz_job=80GB
#PBS -l cpunum_job=18

cd $PBS_O_WORKDIR
module load BaseCPU

mpirun -n 9 ./requester.o : -n 1 ./coupler.o : -n 4 ./worker_1.o : -n 4 ./worker_2.o