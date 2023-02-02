#include <stdio.h>
#include <mpi.h>
#include "ctca.h"

// #define N (1024UL*1024*1024)
#define N 1024

int main()
{
    int myrank, nprocs, progid;
    int intparams[2];
    double data[N];
    int i;
    size_t j;
    int prognum = 2;
    
    printf("requester init\n");
    CTCAR_init();
    printf("requester init done\n");

    MPI_Comm_size(CTCA_subcomm, &nprocs);
    MPI_Comm_rank(CTCA_subcomm, &myrank);

    CTCAR_prof_start_total();
    CTCAR_prof_start();
    CTCAR_prof_start_calc();

    for (i = 0; i < 10; i++) {
        progid = i % prognum;
        intparams[0] = progid;
        intparams[1] = i;

        for (j = 0; j < N; j++)
            data[j] = j;

        if (myrank == 0) 
            CTCAR_sendreq_withreal8(intparams, 2, data, N);

    }

    CTCAR_prof_stop_calc();
    CTCAR_prof_stop();
    CTCAR_prof_stop_total();

    fprintf(stderr, "%d: requester finalize\n", myrank);
    CTCAR_finalize();
}
