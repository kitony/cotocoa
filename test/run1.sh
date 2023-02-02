#!/bin/bash
#PBS -q SQUID
#PBS --group=K2206
#PBS -l elapstim_req=1:00:00
#PBS -b 1
#PBS -T necmpi
#PBS --venum-lhost=8

module load BaseVEC

mpirun  -n 2 /sqfs/home/u6b324/cotocoa/test/sample1_requester_c : -n 1 /sqfs/home/u6b324/cotocoa/test/sample1_coupler_c : -n 2 /sqfs/home/u6b324/cotocoa/test/sample1_worker1_c : -n 2 /sqfs/home/u6b324/cotocoa/test/sample1_worker2_c










