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
    int j;
    int tmp;
    //int prognum = 2;
    int *a;
    int *id;
    a = (int *)malloc(N * N * 512 * sizeof(int));
    id = (int *)malloc(sizeof(int));
    
    CTCAR_init();
    CTCAR_prof_start_total();
    CTCAR_prof_start();

    MPI_Comm_size(CTCA_subcomm, &nprocs);
    MPI_Comm_rank(CTCA_subcomm, &myrank);

    int size = N * N * 512 / nprocs;

    CTCAR_regarea_int(a,N * N * 512,id);

    CTCAR_prof_start_calc();
    for (i = myrank * size;i < (myrank + 1) * size;i++)
    {
        a[i] = (i * myrank) % 7;
    }

    for (j = 0;j < 16;j++)
    {
        for (i = myrank * size;i < (myrank + 1) * size;i++)
        {
            a[i] = (a[i] * myrank) % 11;
        }
    }

    CTCAR_prof_stop_calc();
    CTCAR_prof_stop();
    CTCAR_prof_stop_total();
    CTCAR_finalize();
}
