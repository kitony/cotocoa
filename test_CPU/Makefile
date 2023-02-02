PREFIX=../src_CPU
CC=mpiicc
FC=mpiifort
CC_vec=mpincc -vh
FC_vec=mpinfort -vh
CFLAGS=-I${PREFIX}
LDFLAGS=-L${PREFIX}
LIBS=-lctca
F_LIBS=-lctca_f -lctca_mod

buffer_test:
	$(CC) $(CFLAGS) $(LDFLAGS) requester.c $(LIBS) -o requester.o
	$(CC) $(CFLAGS) $(LDFLAGS) coupler.c $(LIBS) -o coupler.o
	$(CC) $(CFLAGS) $(LDFLAGS) worker_1.c $(LIBS) -o worker_1.o
	$(CC) $(CFLAGS) $(LDFLAGS) worker_2.c $(LIBS) -o worker_2.o

buffer_test_nosuspend:
	$(CC) $(CFLAGS) $(LDFLAGS) requester_nosuspend.c $(LIBS) -o requester_nosuspend.o
	$(CC) $(CFLAGS) $(LDFLAGS) coupler_nosuspend.c $(LIBS) -o coupler_nosuspend.o
	$(CC) $(CFLAGS) $(LDFLAGS) worker_nosuspend_1.c $(LIBS) -o worker_nosuspend_1.o
	$(CC) $(CFLAGS) $(LDFLAGS) worker_nosuspend_2.c $(LIBS) -o worker_nosuspend_2.o

buffer_test_vec:
	$(CC_vec) $(CFLAGS) $(LDFLAGS) requester.c $(LIBS) -o requester_vh.o 
	$(CC_vec) $(CFLAGS) $(LDFLAGS) coupler.c $(LIBS) -o coupler_vh.o
	$(CC_vec) $(CFLAGS) $(LDFLAGS) worker.c $(LIBS) -o worker_vh.o
	$(CC_vec) $(CFLAGS) $(LDFLAGS) worker_r.c $(LIBS) -o worker_r_vh.o

remove:
	rm run.sh.*