#include <stdio.h>
#include <mpi.h>
#include "ctca.h"
#include <stdlib.h>

int main()
{
    int num_proc, my_rank;
    CTCAW_init(0, 4);
    MPI_Comm_size(MPI_COMM_WORLD, &num_proc);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    int a = 0;
    int tmp;
    int start[2], end[2];
    int *recv;
    int *recv_twodimension[150];
    int i, j;

    
    start[0] = ((my_rank - 10) / 2) * 150;
    end[0] = ((my_rank - 10) / 2 + 1) * 150;

    start[1] = ((my_rank - 10) % 2) * 150;
    end[1] = ((my_rank - 10) % 2 + 1) * 150;

    recv = (int *)malloc(150 * 150 * sizeof(int));
    for (i = 0;i < 150;i++)
    {
        recv_twodimension[i] = recv + 150 * i;
    }
    CTCAW_buffer_init_int(20, 100, start, end);
    while(1)
    {
        tmp = CTCAW_get_data_int(recv);
        if (tmp == 1)
        {
            //do calculation
            printf("worker%d_outside:show recv, recv[0][0] is %d, recv[50][50] is %d, recv[149][149] is %d\n", my_rank, recv_twodimension[0][0], recv_twodimension[50][50], recv_twodimension[149][149]);
            a++;
        }
        else if (tmp == 2)
        {
            break;
        }
    }
    if (my_rank == 11)
    {
        for (j = 0;j < 150;j++)
        {
            for (i = 0;i < 150;i++)
            {
                printf("worker_outside:j is %d, i is %d, the value of recv is %d\n", j, i, recv_twodimension[j][i]);
            }
        }
    }
    printf("worker:a is %d\n", a);
    CTCAW_buffer_free();
    CTCAW_finalize();
}
