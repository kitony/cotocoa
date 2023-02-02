PREFIX=../src_VH
CC=mpincc -vh
FC=mpinfort -vh
CFLAGS=-I${PREFIX}
LDFLAGS=-L${PREFIX}
LIBS=-lctca
F_LIBS=-lctca_f -lctca_mod

all: ${PROGS}

buffer_test_VH:
	$(CC) $(CFLAGS) $(LDFLAGS) requester.c $(LIBS) -o requester_H
	$(CC) $(CFLAGS) $(LDFLAGS) coupler.c $(LIBS) -o coupler_H
	$(CC) $(CFLAGS) $(LDFLAGS) worker_1.c $(LIBS) -o worker_1_H
	$(CC) $(CFLAGS) $(LDFLAGS) worker_2.c $(LIBS) -o worker_2_H


test:
	$(CC) $(CFLAGS) $(LDFLAGS) testr.c $(LIBS) -o testr_c_H
	$(CC) $(CFLAGS) $(LDFLAGS) testc.c $(LIBS) -o testc_c_H
	$(CC) $(CFLAGS) $(LDFLAGS) testw1.c $(LIBS) -o testw1_c_H
	$(CC) $(CFLAGS) $(LDFLAGS) testw2.c $(LIBS) -o testw2_c_H

clean:
	rm -f *.o *.mod ${PROGS}

remove:
	rm io_test.* core.*