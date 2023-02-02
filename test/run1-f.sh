#!/bin/bash
#PBS -q SQUID
#PBS --group=G15240
#PBS -l elapstim_req=1:00:00
#PBS --venode=1

cd $PBS_O_WORKDIR
module load BaseVEC

mpirun -np 2 ${NQSV_MPIOPTS} ./sample1_requester_c :  -np 1 ${NQSV_MPIOPTS} ./sample1_coupler_c : -np 2 ${NQSV_MPIOPTS} ./sample1_worker1_c :    -np 2 ${NQSV_MPIOPTS} ./sample1_worker2_c










