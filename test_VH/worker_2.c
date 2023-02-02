#include <stdio.h>
#include <mpi.h>
#include "ctca.h"
#include <stdlib.h>
#include <unistd.h>

int main()
{
    printf("start 1\n");
    int num_proc, my_rank;
    CTCAW_init(1, 4);
    MPI_Comm_size(MPI_COMM_WORLD, &num_proc);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    char *name;
    name = (char *)malloc(20 * sizeof(int));
    int len;
    MPI_Get_processor_name(name,&len);
    printf("my processor is %s, my rank is %d\n",name,my_rank);
    //printf("size is %d\n", sizeof(MPI_AINT));

    int a = 0;
    int tmp;
    int start[2], end[2];
    int recv[1000][1500][1500];
    int grid[2], datasize[2];
    int i, j;
    int sum;
    int *tmp_address;
    int signal = 0;
    //int *tmp_receiver[1500];
    //printf("worker%d_outside:show recv, recv[0][0] is %d, recv[50][50] is %d, recv[149][149] is %d\n", my_rank, recv[0][0], recv[50][50], recv[149][149]);
    
    /*
    start[0] = ((my_rank - 10) / 2) * 2250;
    end[0] = ((my_rank - 10) / 2 + 1) * 2250;

    start[1] = ((my_rank - 10) % 2) * 2250;
    end[1] = ((my_rank - 10) % 2 + 1) * 2250;
    */
    


    start[0] = ((my_rank - 10) / 2) * 1500;
    end[0] = ((my_rank - 10) / 2 + 1) * 1500;

    start[1] = ((my_rank - 10) % 2) * 1500;
    end[1] = ((my_rank - 10) % 2 + 1) * 1500;
    

   /*
    if (my_rank == 0)
    {
        start[0] = 0;
        end[0] = 0;

        start[1] = 0;
        end[1] = 0;
    }
    else
    {
        start[0] = 0;
        end[0] = 4500;

        start[1] = 3000;
        end[1] = 4500;
    }
    */

    /*
        start[0] = 1501;
        end[0] = 4500;

        start[1] = 0;
        end[1] = 4500;
    */

   grid[0] = 2;
   grid[1] = 2;
   datasize[0] = 3000;
   datasize[1] = 3000;

    CTCAW_buffer_init(grid, datasize, recv[0][0]);
    while(1)
    { 
        tmp = CTCAW_buffer_read_data();
        if (tmp == 1)
        {
            tmp_address = CTCAW_buffer_get_address(recv[0][0]);
            //do calculation
            //calculation();
            if (my_rank >= 14 && my_rank <= 17)
            {
                printf("worker%d_outside1:%d, %d, %d, %d, %d, %d, %d, %d\n",
                my_rank, tmp_address[0], tmp_address[500], tmp_address[1000], tmp_address[1500], 
                tmp_address[499 * 1500], tmp_address[500 * 1500], tmp_address[999 * 1500], tmp_address[1000 * 1500]);
            }

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
