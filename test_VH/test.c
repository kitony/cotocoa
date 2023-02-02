#include <stdio.h>
#include <mpi.h>

int main(int argc,char **argv)
{
    MPI_Init(&argc,&argv);
    int size,rank;
    int i;
    int a[16];
    int b[16];
    MPI_Comm_size(MPI_COMM_WORLD,&size);
    MPI_Comm_rank(MPI_COMM_WORLD,&rank);

    for (i = 0;i < 16;i++)
    {
        a[i] = rank;
    }
    MPI_Allgather(a + rank * 2,2,MPI_INT,b,2,MPI_INT,MPI_COMM_WORLD);
    for (i = 0;i < 16;i++)
    {
        printf("my rank is %d,b[%d] is %d\n",rank,i,b[i]);
    }
    //printf("my rank is %d,b[]\n",rank);

    MPI_Finalize();
}
