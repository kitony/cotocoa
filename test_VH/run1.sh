#!/bin/sh
#PBS --group=G15240
#PBS -q SQUID
#PBS -T necmpi
#PBS -l elapstim_req=00:10:00
#PBS --venode=1
#PBS -N io_test
 

 
#PBS -v MSEP="/opt/nec/ve/bin/mpisep.sh"
#PBS -v VH="-vh"
 
cd $PBS_O_WORKDIR
module load BaseVEC

mpirun -v   -nn 1 -np 2 ${MSEP} ./sample1_requester_c : -nn 1 -np 1 ${MSEP} ./sample1_coupler_c : \
            -nn 1 -np 2 ${MSEP} ./sample1_worker1_c : -nn 1 -np 2 ${MSEP} ./sample1_worker2_c