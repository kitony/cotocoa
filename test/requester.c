#include <stdio.h>
#include <mpi.h>
#include "ctca.h"
#include <stdlib.h>

int main()
{
    CTCAR_init();
    int num_proc, my_rank;
    int my_location_start[2], my_location_end[2];
    int data[1000][1000];
    int i, j, k;
    double t0,t1,t_all;
    t_all = 0;

    MPI_Comm_size(MPI_COMM_WORLD, &num_proc);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    char *name;
    name = (char *)malloc(20 * sizeof(int));
    int len;
    MPI_Get_processor_name(name,&len);
    printf("my processor is %s, my rank is %d\n",name,my_rank);

    my_location_start[0] = (my_rank / 3) * 1000;
    my_location_end[0] = (my_rank / 3 + 1) * 1000;

    my_location_start[1] = (my_rank % 3) * 1000;
    my_location_end[1] = (my_rank % 3 + 1) * 1000;

    CTCAR_buffer_init_int(1, 2, my_location_start, my_location_end);
    t0 = MPI_Wtime();
    for (k = 0;k < 1000;k++)
    {
        //calculation start
        for (j = 0;j < 1000;j++)
        {
            for (i = 0;i < 1000;i++)
            {
                //data[j][i] = k * 10000000 + j * 1000 + i + my_rank * 1000000;
                data[j][i] = k * 10000 + j * 10 + my_rank;
            }
        }
        //calculation end
        //load the result data to buffer
        CTCAR_buffer_load_data_int(data[0]);
    }
    //CTCAR_buffer_over();
    t1 = MPI_Wtime();
    t_all = t1 - t0;
    printf("requester: my rank is %d, used time is %f\n", my_rank, t_all);

    CTCAR_buffer_free();
    CTCAR_finalize();
}
