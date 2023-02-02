PREFIX=../src
CC=mpincc
FC=mpinfort
VH=VH
CFLAGS=-I${PREFIX}
LDFLAGS=-L${PREFIX}
LIBS=-lctca
F_LIBS=-lctca_f -lctca_mod

PROGS = buffer_test_nosuspend_VE buffer_test_nosuspend_VH buffer_test_VE buffer_test_VH

all: ${PROGS}

buffer_test_VE:
	$(CC) $(CFLAGS) $(LDFLAGS) requester.c $(LIBS) -o requester_ve
	$(CC) $(CFLAGS) $(LDFLAGS) coupler.c $(LIBS) -o coupler_ve
	$(CC) $(CFLAGS) $(LDFLAGS) worker_1.c $(LIBS) -o worker_1_ve
	$(CC) $(CFLAGS) $(LDFLAGS) worker_2.c $(LIBS) -o worker_2_ve

buffer_test_VH:
	$(CC) -vh $(CFLAGS)_$(VH) $(LDFLAGS)_$(VH) requester.c $(LIBS) -o requester_vh
	$(CC) -vh $(CFLAGS)_$(VH) $(LDFLAGS)_$(VH) coupler.c $(LIBS) -o coupler_vh
	$(CC) -vh $(CFLAGS)_$(VH) $(LDFLAGS)_$(VH) worker_1.c $(LIBS) -o worker_1_vh
	$(CC) -vh $(CFLAGS)_$(VH) $(LDFLAGS)_$(VH) worker_2.c $(LIBS) -o worker_2_vh


buffer_test_nosuspend_VE:
	$(CC) $(CFLAGS) $(LDFLAGS) requester_nosuspend.c $(LIBS) -o requester_nosuspend_ve
	$(CC) $(CFLAGS) $(LDFLAGS) coupler_nosuspend.c $(LIBS) -o coupler_nosuspend_ve
	$(CC) $(CFLAGS) $(LDFLAGS) worker_nosuspend_1.c $(LIBS) -o worker_nosuspend_1_ve
	$(CC) $(CFLAGS) $(LDFLAGS) worker_nosuspend_2.c $(LIBS) -o worker_nosuspend_2_ve

buffer_test_nosuspend_VH:
	$(CC) -vh $(CFLAGS)_$(VH) $(LDFLAGS)_$(VH) requester_nosuspend.c $(LIBS) -o requester_nosuspend_vh
	$(CC) -vh $(CFLAGS)_$(VH) $(LDFLAGS)_$(VH) coupler_nosuspend.c $(LIBS) -o coupler_nosuspend_vh
	$(CC) -vh $(CFLAGS)_$(VH) $(LDFLAGS)_$(VH) worker_nosuspend_1.c $(LIBS) -o worker_nosuspend_1_vh
	$(CC) -vh $(CFLAGS)_$(VH) $(LDFLAGS)_$(VH) worker_nosuspend_2.c $(LIBS) -o worker_nosuspend_2_vh