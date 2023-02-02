#!/bin/sh
#PBS --group=G15240
#PBS -q DBG
#PBS -T necmpi
#PBS -b 1
#PBS -l elapstim_req=00:10:00
#PBS --venum-lhost=8

#PBS -v MSEP="/opt/nec/ve/bin/mpisep.sh"
#PBS -v VH="-vh"
 
cd $PBS_O_WORKDIR
module load BaseVEC

mpirun -v   -nn 1 ${VH} -np 2 ${MSEP} ./sample1_requester_c_H : -nn 1 ${VH} -np 1 ${MSEP} ./sample1_coupler_c_H : \
            -nn 1 ${VH} -np 2 ${MSEP} ./sample1_worker1_c_H : -nn 1 ${VH} -np 2 ${MSEP} ./sample1_worker2_c_H