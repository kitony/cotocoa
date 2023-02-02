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
    int prognum = 3;
    int *id;
    int *a;
    printf("before\n");
    a = (int *)malloc(1024 * 1024 * 128 * sizeof(int));
    printf("after\n");
    id = (int *)malloc(sizeof(int));

    printf("coupler init\n");
    CTCAC_init_detail(10, 10, 10, N*sizeof(double), 10);
    CTCAC_prof_start();
    CTCAC_regarea_int(id);
    
    //printf("coupler init done\n");

    MPI_Comm_size(CTCA_subcomm, &nprocs);
    MPI_Comm_rank(CTCA_subcomm, &myrank);

    /*
    while (1) {
        printf("coupler poll\n");
        CTCAC_pollreq_withreal8(reqinfo, &fromrank, intparams, 2, data, N);
        printf("coupler poll done\n");

        if (CTCAC_isfin()) 
            break;

        if (fromrank >= 0) {
        printf("coupler enq\n");
            progid = intparams[0];
            CTCAC_enqreq_withreal8(reqinfo, progid, intparams, 2, data, N);
        printf("coupler enq done\n");
        }
    }

    printf("coupler fin\n");

    fprintf(stderr, "%d: coupler finalize\n", myrank);
    */
    CTCAC_readarea_int(0,0,0,1024 * 1024 * 128,a);
    CTCAC_prof_stop();
    CTCAC_finalize();
}
