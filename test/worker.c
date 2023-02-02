#include <stdio.h>
#include <mpi.h>
#include "ctca.h"
#include <stdlib.h>

int main()
{
    printf("start 1\n");
    int num_proc, my_rank;
    CTCAW_init(0, 4);
    MPI_Comm_size(MPI_COMM_WORLD, &num_proc);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    int a = 0;
    int tmp;
    int start[2], end[2];
    int recv[500][1000][1000];
    int i, j;
    int sum;
    int *tmp_address;
    //int *tmp_receiver[1500];
    //printf("worker%d_outside:show recv, recv[0][0] is %d, recv[50][50] is %d, recv[149][149] is %d\n", my_rank, recv[0][0], recv[50][50], recv[149][149]);
    
    /*
    start[0] = ((my_rank - 10) / 2) * 1500;
    end[0] = ((my_rank - 10) / 2 + 1) * 1500;

    start[1] = ((my_rank - 10) % 2) * 1500;
    end[1] = ((my_rank - 10) % 2 + 1) * 1500;
    */

   /*
    start[0] = ((my_rank - 10) / 2) * 1000;
    end[0] = ((my_rank - 10) / 2 + 1) * 1000;

    start[1] = ((my_rank - 10) % 2) * 1000;
    end[1] = ((my_rank - 10) % 2 + 1) * 1000;
    */

    start[0] = 2000;
    end[0] = 3000;

    start[1] = 2000;
    end[1] = 3000;

    CTCAW_buffer_init(start, end, 1);
    while(1)
    {
        sum = 0;
        tmp = CTCAW_buffer_read_data(recv[0][0]);
        if (tmp == 1)
        {
            tmp_address = CTCAW_buffer_get_address(recv[0][0]);
            //tmp_receiver[0] = tmp_address;
            //do calculation
            /*
            for (j = 0;j < 15000;j++)
            {
                for (i = 0;i < 15000;i++)
                {
                    sum += tmp_receiver[j][i];
                }
            }
            */
            
            if (my_rank == 11)
            {
                printf("worker%d_outside1:show recv, recv[0][0] is %d, recv[50][50] is %d, recv[149][149] is %d\n", my_rank, tmp_address[0], tmp_address[50 * 150 + 50], tmp_address[0]);
            }
            
            //printf("worker%d_outside1:show recv, recv[0][0] is %d, recv[50][50] is %d, recv[149][149] is %d\n", my_rank, tmp_address[0], tmp_address[50 * 150 + 50], tmp_address[149 * 150 + 149]);
            //printf("worker%d_outside1:show recv, recv[0][0] is %d, recv[50][50] is %d, recv[149][149] is %d\n", my_rank, tmp_receiver[0][0], tmp_receiver[50][50], tmp_receiver[149][149]);
        }
        else if (tmp == 2)
        {
            break;
        }
    }
    
    /*
    if (my_rank == 11)
    {
        for (j = 0;j < 150;j++)
        {
            for (i = 0;i < 150;i++)
            {
                printf("worker_outside1:j is %d, i is %d, the value of recv is %d\n", j, i, tmp_address[j * 150 + i]);
            }
        }
    }
    */
    
    CTCAW_buffer_free();
    CTCAW_finalize();
}
