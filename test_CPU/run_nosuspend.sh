#!/bin/sh
#PBS -q SQUID
#PBS --group=K2206
#PBS -T intmpi
#PBS -l elapstim_req=0:10:00

#PBS -b 2
#PBS -l memsz_job=150GB
#PBS -l cpunum_job=76

cd $PBS_O_WORKDIR
module load BaseCPU

mpirun -n 9 ./requester_nosuspend.o : -n 1 ./coupler_nosuspend.o : -n 4 ./worker_nosuspend_1.o : -n 4 ./worker_nosuspend_2.o