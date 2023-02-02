#!/bin/sh
#PBS -l nodes=4:ppn=2
#PBS -q Q1
#PBS -j oe

cd $PBS_O_WORKDIR

/home/nanri/local/openmpi-3.1.6-pc01-gcc10.1.0/bin/mpirun --hostfile $PBS_NODEFILE  -np 2 ./sample3_requester_f : -np 1 ./sample3_coupler_f : -np 2 ./sample3_worker_f 










