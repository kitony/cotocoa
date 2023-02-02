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
    int reqinfo[CTCAC_REQINFOITEMS];
    double data[N];
    int i, j, k;
    //int prognum = 3;
    int *id;
    int *a;
    a = (int *)malloc(N * N * 128 * sizeof(int));
    id = (int *)malloc(sizeof(int));

    CTCAC_init_detail(10, 10, 10, N*sizeof(double), 10);
    CTCAC_prof_start();
    CTCAC_regarea_int(id);

    MPI_Comm_size(CTCA_subcomm, &nprocs);
    MPI_Comm_rank(CTCA_subcomm, &myrank);
    int size = N * N * 128 / nprocs;

    CTCAC_readarea_int(0,0,0,N * N * 128,a);

    CTCAC_prof_start_calc();
    for (i = myrank * size;i < (myrank + 1) * size;i++)
        {
            a[i] = (a[i] * myrank) % 11;
        }

    CTCAC_prof_stop_calc();
    CTCAC_prof_stop();
    CTCAC_finalize();
}
