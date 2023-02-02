#include <stdio.h>
#include <mpi.h>
#include "ctca.h"

//#define N (1024UL*1024*1024)
#define N 1024

int main()
{
    int myrank, nprocs, progid, fromrank;
    int intparams[2];
    double data[N];
    int i, j, k, c;
    int prognum = 2;

    printf("worker2 init\n");
    CTCAW_init(1, 2);
    printf("worker2 init done\n");

    MPI_Comm_size(CTCA_subcomm, &nprocs);
    MPI_Comm_rank(CTCA_subcomm, &myrank);

    CTCAW_prof_start();
    CTCAW_prof_start_calc();

    while(1) {
        CTCAW_pollreq_withreal8(&fromrank, intparams, 2, data, N);
        c = intparams[1];

        if (CTCAW_isfin()) 
            break;

        printf("worker2 poll req done\n");

//        MPI_Bcast(data, 6*400, MPI_DOUBLE, 0, CTCA_subcomm);

//        printf("worker2 bcast done\n");

        printf("worker2 rank %d c %d data %f %f %f ... %f %f\n", myrank, c, data[0], data[1], data[2], data[N-2], data[N-1]);
        
        CTCAW_complete();
        printf("worker2 complete done\n");
    }

    CTCAW_prof_stop_calc();
    CTCAW_prof_stop();

    fprintf(stderr, "%d: worker2 finalize\n", myrank);
    CTCAW_finalize();
}
