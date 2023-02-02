#!/bin/bash
#PBS -q SQUID
#PBS --group=G15240
#PBS -l elapstim_req=1:00:00
#PBS --venode=3

#PBS -v MSEP="/opt/nec/ve/bin/mpisep.sh"
#PBS -v VH="-vh"
 
cd $PBS_O_WORKDIR
module load BaseVEC

mpirun -v -ve 0 -np 2 ${MSEP} ./a.out : -ve 1 -np 1 ${MSEP} ./a.out