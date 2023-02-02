#include <stdio.h>
#include <mpi.h>
#include "ctca.h"
#include <stdlib.h>

//#define N (1024UL*1024*1024)
#define N 1024

int main()
{
    int myrank, nprocs, progid, fromrank;
    int intparams[2];
    double data[N];
    int i, j, k, c;
    int prognum = 2;
    int *id;
    int *a;
    printf("before\n");
    a = (int *)malloc(1024 * 1024 * 128 * sizeof(int));
    printf("after\n");
    id = (int *)malloc(sizeof(int));

    printf("worker2 init\n");
    CTCAW_init(1, 2);
    CTCAW_prof_start();
    CTCAW_regarea_int(id);
    
    //printf("worker2 init done\n");

    MPI_Comm_size(CTCA_subcomm, &nprocs);
    MPI_Comm_rank(CTCA_subcomm, &myrank);

    /*
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

    fprintf(stderr, "%d: worker2 finalize\n", myrank);
    */

    CTCAW_readarea_int(0,0,0,1024 * 1024 * 128,a);
    //CTCAW_complete();
    for (i = 0;i < 10;i++)
    {
        printf("the value is %d\n",a[i]);
    }
    
    CTCAW_prof_stop();
    CTCAW_finalize();
}
