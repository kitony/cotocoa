PREFIX=../src
CC=mpincc
FC=mpinfort
VH=VH
CFLAGS=-I${PREFIX}
LDFLAGS=-L${PREFIX}
LIBS=-lctca
F_LIBS=-lctca_f -lctca_mod

PROGS = sample0_requester_c sample0_coupler_c sample0_worker_c \
	    sample1_requester_c sample1_coupler_c sample1_worker1_c sample1_worker2_c sample1_worker3_c \
        sample1_requester_f sample1_coupler_f sample1_worker1_f sample1_worker2_f sample1_worker3_f \
        sample2_requester_f sample2_coupler_f sample2_worker1_f sample2_worker2_f sample2_worker3_f \
        sample3_requester_f sample3_coupler_f sample3_worker_f \
        sample4_requester_f sample4_coupler_f sample4_worker_f 

all: ${PROGS}

sample0_requester_c: sample0_requester.c
	$(CC) $(CFLAGS) $(LDFLAGS) sample0_requester.c $(LIBS) -o sample0_requester_c

sample0_coupler_c: sample0_coupler.c
	$(CC) $(CFLAGS) $(LDFLAGS) sample0_coupler.c $(LIBS) -o sample0_coupler_c

sample0_worker_c: sample0_worker.c
	$(CC) $(CFLAGS) $(LDFLAGS) sample0_worker.c $(LIBS) -o sample0_worker_c

sample1_requester_c: sample1_requester.c
	$(CC) $(CFLAGS) $(LDFLAGS) sample1_requester.c $(LIBS) -o sample1_requester_c

sample1_coupler_c: sample1_coupler.c
	$(CC) $(CFLAGS) $(LDFLAGS) sample1_coupler.c $(LIBS) -o sample1_coupler_c

sample1_worker1_c: sample1_worker1.c
	$(CC) $(CFLAGS) $(LDFLAGS) sample1_worker1.c $(LIBS) -o sample1_worker1_c

sample1_worker2_c: sample1_worker2.c
	$(CC) $(CFLAGS) $(LDFLAGS) sample1_worker2.c $(LIBS) -o sample1_worker2_c

sample1_worker3_c: sample1_worker3.c
	$(CC) $(CFLAGS) $(LDFLAGS) sample1_worker3.c $(LIBS) -o sample1_worker3_c

sample1_requester_f: sample1_requester.f90
	$(FC) $(CFLAGS) $(LDFLAGS) sample1_requester.f90 $(F_LIBS) $(LIBS) -o sample1_requester_f

sample1_coupler_f: sample1_coupler.f90
	$(FC) $(CFLAGS) $(LDFLAGS) sample1_coupler.f90 $(F_LIBS) $(LIBS) -o sample1_coupler_f

sample1_worker1_f: sample1_worker1.f90
	$(FC) $(CFLAGS) $(LDFLAGS) sample1_worker1.f90 $(F_LIBS) $(LIBS) -o sample1_worker1_f

sample1_worker2_f: sample1_worker2.f90
	$(FC) $(CFLAGS) $(LDFLAGS) sample1_worker2.f90 $(F_LIBS) $(LIBS) -o sample1_worker2_f

sample1_worker3_f: sample1_worker3.f90
	$(FC) $(CFLAGS) $(LDFLAGS) sample1_worker3.f90 $(F_LIBS) $(LIBS) -o sample1_worker3_f

sample2_requester_f: sample2_requester.f90
	$(FC) $(CFLAGS) $(LDFLAGS) sample2_requester.f90 $(F_LIBS) $(LIBS) -o sample2_requester_f

sample2_coupler_f: sample2_coupler.f90 
	$(FC) $(CFLAGS) $(LDFLAGS) sample2_coupler.f90 $(F_LIBS) $(LIBS) -o sample2_coupler_f

sample2_worker1_f: sample2_worker1.f90 
	$(FC) $(CFLAGS) $(LDFLAGS) sample2_worker1.f90 $(F_LIBS) $(LIBS) -o sample2_worker1_f

sample2_worker2_f: sample2_worker2.f90 
	$(FC) $(CFLAGS) $(LDFLAGS) sample2_worker2.f90 $(F_LIBS) $(LIBS) -o sample2_worker2_f

sample2_worker3_f: sample2_worker3.f90 
	$(FC) $(CFLAGS) $(LDFLAGS) sample2_worker3.f90 $(F_LIBS) $(LIBS) -o sample2_worker3_f

sample3_requester_f: sample3_requester.f90
	$(FC) $(CFLAGS) $(LDFLAGS) sample3_requester.f90 $(F_LIBS) $(LIBS) -o sample3_requester_f

sample3_coupler_f: sample3_coupler.f90 
	$(FC) $(CFLAGS) $(LDFLAGS) sample3_coupler.f90 $(F_LIBS) $(LIBS) -o sample3_coupler_f

sample3_worker_f: sample3_worker.f90 
	$(FC) $(CFLAGS) $(LDFLAGS) sample3_worker.f90 $(F_LIBS) $(LIBS) -o sample3_worker_f

sample4_requester_f: sample4_requester.f90
	$(FC) $(CFLAGS) $(LDFLAGS) sample4_requester.f90 $(F_LIBS) $(LIBS) -o sample4_requester_f

sample4_coupler_f: sample4_coupler.f90 
	$(FC) $(CFLAGS) $(LDFLAGS) sample4_coupler.f90 $(F_LIBS) $(LIBS) -o sample4_coupler_f

sample4_worker_f: sample4_worker.f90 
	$(FC) $(CFLAGS) $(LDFLAGS) sample4_worker.f90 $(F_LIBS) $(LIBS) -o sample4_worker_f

test:
	$(CC) $(CFLAGS) $(LDFLAGS) testr.c $(LIBS) -o testr_c
	$(CC) $(CFLAGS) $(LDFLAGS) testc.c $(LIBS) -o testc_c
	$(CC) $(CFLAGS) $(LDFLAGS) testw1.c $(LIBS) -o testw1_c
	$(CC) $(CFLAGS) $(LDFLAGS) testw2.c $(LIBS) -o testw2_c

test_VH:
	$(CC) -vh $(CFLAGS)_$(VH) $(LDFLAGS)_$(VH) testr.c $(LIBS) -o ../test_VH/testr_c_H
	$(CC) -vh $(CFLAGS)_$(VH) $(LDFLAGS)_$(VH) testc.c $(LIBS) -o ../test_VH/testc_c_H
	$(CC) -vh $(CFLAGS)_$(VH) $(LDFLAGS)_$(VH) testw1.c $(LIBS) -o ../test_VH/testw1_c_H
	$(CC) -vh $(CFLAGS)_$(VH) $(LDFLAGS)_$(VH) testw2.c $(LIBS) -o ../test_VH/testw2_c_H

buffer_test:
	$(CC) $(CFLAGS) $(LDFLAGS) requester.c $(LIBS) -o requester
	$(CC) $(CFLAGS) $(LDFLAGS) coupler.c $(LIBS) -o coupler
	$(CC) $(CFLAGS) $(LDFLAGS) worker_1.c $(LIBS) -o worker_1

buffer_test_nosuspend:
	$(CC) $(CFLAGS) $(LDFLAGS) requester_nosuspend.c $(LIBS) -o requester_nosuspend
	$(CC) $(CFLAGS) $(LDFLAGS) coupler_nosuspend.c $(LIBS) -o coupler_nosuspend
	$(CC) $(CFLAGS) $(LDFLAGS) worker_nosuspend_1.c $(LIBS) -o worker_nosuspend_1
	$(CC) $(CFLAGS) $(LDFLAGS) worker_nosuspend_2.c $(LIBS) -o worker_nosuspend_2

buffer_test_clean:
	rm requester coupler worker worker_r

buffer_test_to_VH:
	$(CC) $(CFLAGS) $(LDFLAGS) requester.c $(LIBS) -o ../test_VH/requester
	$(CC) $(CFLAGS) $(LDFLAGS) coupler.c $(LIBS) -o ../test_VH/coupler
	$(CC) $(CFLAGS) $(LDFLAGS) worker.c $(LIBS) -o ../test_VH/worker
	$(CC) $(CFLAGS) $(LDFLAGS) worker_r.c $(LIBS) -o ../test_VH/worker_r

buffer_test_VH:
	$(CC) -vh $(CFLAGS)_$(VH) $(LDFLAGS)_$(VH) requester.c $(LIBS) -o ../test_VH/requester_H
	$(CC) -vh $(CFLAGS)_$(VH) $(LDFLAGS)_$(VH) coupler.c $(LIBS) -o ../test_VH/coupler_H
	$(CC) -vh $(CFLAGS)_$(VH) $(LDFLAGS)_$(VH) worker.c $(LIBS) -o ../test_VH/worker_H
	$(CC) -vh $(CFLAGS)_$(VH) $(LDFLAGS)_$(VH) worker_r.c $(LIBS) -o ../test_VH/worker_r_H

clean:
	rm -f *.o *.mod ${PROGS}

remove:
	rm run*.sh.* core.* 

copy:
	cp requester ../test_VH/requester
	cp coupler ../test_VH/coupler
	cp worker ../test_VH/worker
	cp worker_r ../test_VH/worker_r

copy_test:
	cp test*_c ../test_VH
	
copy_tmp:
	cp test*.c ../../test

copy_good:
	cp test*.c ../test_VH