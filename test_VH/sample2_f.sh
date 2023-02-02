#!/bin/bash
#PBS -q SQUID
#PBS --group=G15240
#PBS -b 1
#PBS -T necmpi
#PBS -l elapstim_req=1:00:00
#PBS --venode=8

cd $PBS_O_WORKDIR
module load BaseVEC

mpirun -vh -n 4 ./sample2_requester_f : -vh -n 1 ./sample2_coupler_f : -vh -n 8 ./sample2_worker1_f : -vh -n 8 ./sample2_worker2_f : -vh -n 8 ./sample2_worker3_f









