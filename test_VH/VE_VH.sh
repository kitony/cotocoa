#!/bin/bash
#PBS -q SQUID
#PBS --group=G15240
#PBS -T necmpi
#PBS -b 2
#PBS -l elapstim_req=1:00:00
#PBS --venum-lhost=8 --cpunum-lhost=2
#PBS --use-hca=1
 
cd $PBS_O_WORKDIR
module load BaseVEC

mpirun -v   -host 1 -ve 0-7 -np 40 ./testr_c : -vh -host 1 -np 8 ./testc_c_H : \
            -host 0 -ve 0-3 -np 10 ./testw1_c : -host 0 -ve 0-3 -np 10 ./testw2_c

#mpirun -host 0 -ve 0-7 -np 80 ./a.out : -host 1 -ve 0-7 -np 80 ./a.out

