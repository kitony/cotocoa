#include <stdio.h>
#include <mpi.h>
#include "ctca.h"
#include <stdlib.h>

int main()
{
    int num_proc, my_rank;
    CTCAW_init(1, 4);
    MPI_Comm_size(MPI_COMM_WORLD, &num_proc);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    int a = 0;
    int tmp;
    int start[2], end[2];
    int recv[477][2250][2250];
    int i, j;
    int sum;
    int *tmp_address;

    char *name;
    name = (char *)malloc(20 * sizeof(int));
    int len;
    MPI_Get_processor_name(name,&len);
    printf("my processor is %s, my rank is %d\n",name,my_rank);
    //int *tmp_receiver[1500];
    //printf("worker%d_outside:show recv, recv[0][0] is %d, recv[50][50] is %d, recv[149][149] is %d\n", my_rank, recv[0][0], recv[50][50], recv[149][149]);
    
    /*
    start[0] = ((my_rank - 14) / 2) * 1500;
    end[0] = ((my_rank - 14) / 2 + 1) * 1500;

    start[1] = ((my_rank - 14) % 2) * 1500;
    end[1] = ((my_rank - 14) % 2 + 1) * 1500;
    */

    start[0] = ((my_rank - 14) / 2) * 2250;
    end[0] = ((my_rank - 14) / 2 + 1) * 2250;

    start[1] = ((my_rank - 14) % 2) * 2250;
    end[1] = ((my_rank - 14) % 2 + 1) * 2250;

    CTCAW_buffer_init_int(1000, start, end);
    while(1)
    {
        sum = 0;
        tmp = CTCAW_buffer_get_data_int(recv[0][0]);
        if (tmp == 1)
        {
            tmp_address = get_address(recv[0][0]);
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
            
            if (my_rank == 15)
            {
                printf("worker%d_outside2:show recv, recv[0][0] is %d, recv[50][50] is %d, recv[149][149] is %d\n", my_rank, tmp_address[0], tmp_address[1000 * 2250 + 1000], tmp_address[149 * 2250 + 149]);
            }
            
            //printf("worker%d_outside2:show recv, recv[0][0] is %d, recv[50][50] is %d, recv[149][149] is %d\n", my_rank, tmp_receiver[0][0], tmp_receiver[50][50], tmp_receiver[149][149]);
        }
        else if (tmp == 2)
        {
            break;
        }
    }
    /*
    if (my_rank == 15)
    {
        for (j = 0;j < 150;j++)
        {
            for (i = 0;i < 150;i++)
            {
                printf("worker_outside2:j is %d, i is %d, the value of recv is %d\n", j, i, tmp_address[j * 150 + i]);
            }
        }
    }
    */
    CTCAW_buffer_free();
    CTCAW_finalize();
}
