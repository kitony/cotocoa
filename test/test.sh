#!/bin/bash
#PBS -q SQUID
#PBS --group=G15240
#PBS -l elapstim_req=1:00:00
#PBS --venode=1

cd $PBS_O_WORKDIR
module load BaseVEC

mpirun -v -host 0 -n 2 ./testr_c : -host 0 -n 1 ./testc_c : -host 0 -n 2 ./testw1_c : -host 0 -n 2 ./testw2_c










