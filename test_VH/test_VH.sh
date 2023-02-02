#!/bin/sh
#PBS --group=G15240
#PBS -q SQUID
#PBS -T necmpi
#PBS -l elapstim_req=00:10:00
#PBS --venode=1

#PBS -v MSEP="/opt/nec/ve/bin/mpisep.sh"
#PBS -v VH="-vh"
 
cd $PBS_O_WORKDIR
module load BaseVEC

mpirun -v   -nn 1 ${VH} -np 2 ${MSEP} ./testr_c_H : -nn 1 ${VH} -np 1 ${MSEP} ./testc_c_H : \
            -nn 1 ${VH} -np 2 ${MSEP} ./testw1_c_H : -nn 1 ${VH} -np 2 ${MSEP} ./testw2_c_H