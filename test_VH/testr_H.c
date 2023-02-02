#include <stdio.h>
#include <mpi.h>
#include "ctca.h"
#include <stdlib.h>

// #define N (1024UL*1024*1024)
#define N 1024

int main()
{
    int myrank, nprocs, progid;
    //int intparams[2];
    double data[N];
    int i;
    size_t j;
    int tmp;
    //int prognum = 2;
    int *a;
    int *id;
    printf("before\n");
    a = (int *)malloc(1024 * 1024 * 128 * sizeof(int));
    printf("after\n");
    id = (int *)malloc(sizeof(int));
    
    printf("requester init\n");
    CTCAR_init();
    CTCAR_prof_start_total();
    CTCAR_prof_start();

    MPI_Comm_size(CTCA_subcomm, &nprocs);
    MPI_Comm_rank(CTCA_subcomm, &myrank);

    CTCAR_regarea_int(a,1024 * 1024 * 128,id);
    //printf("requester init done\n");
    for (i = 0;i < 1024 * 1024 * 128;i++)
    {
        a[i] = i % 7;
    }
    /*
    printf("requester init done\n");
    for (i = 0; i < 10; i++) {
        progid = i % prognum;
        intparams[0] = progid;
        intparams[1] = i;
        //#pragma omp parallel for  
        for (j = 0; j < N; j++)
            data[j] = j;

        if (myrank == 0) 
        {
            CTCAR_sendreq_withreal8(intparams, 2, data, N);
        }    
    }
    */

    //fprintf(stderr, "%d: requester finalize\n", myrank);
    CTCAR_prof_stop();
    CTCAR_prof_stop_total();
    CTCAR_finalize();
}
