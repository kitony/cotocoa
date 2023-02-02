#include <stdio.h>
#include <mpi.h>
#include "ctca.h"
#include <stdlib.h>

//#define N (1024UL*1024*1024)
#define N 1024

int main()
{
    int myrank, nprocs, progid, fromrank;
    //int intparams[2];
    //double data[N];
    int i, j, k, c;
    //int prognum = 2;
    int world_rank;
    int *id;
    int *a;
    a = (int *)malloc(N * N * 512 * sizeof(int));
    id = (int *)malloc(sizeof(int));

    CTCAW_init(0, 2);
    CTCAW_prof_start();
    CTCAW_regarea_int(id);

    MPI_Comm_size(CTCA_subcomm, &nprocs);
    MPI_Comm_rank(CTCA_subcomm, &myrank);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    int size = N * N * 512 / nprocs;

    CTCAW_readarea_int(0,0,0,N * N * 512,a);
    CTCAW_prof_start_calc();
    for (j = 0;j < 16;j++)
    {
        for (i = myrank * size;i < (myrank + 1) * size;i++)
        {
            a[i] = (a[i] * myrank) % 12;
        }
    }
    CTCAW_prof_stop_calc();
    CTCAW_prof_stop();
    printf("worker1 done\n");
    CTCAW_finalize();
}
