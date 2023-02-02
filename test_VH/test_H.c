#include <stdio.h>
#include <mpi.h>

int main(int argc,char **argv)
{
    MPI_Init(&argc,&argv);
    printf("signal_H\n");
    MPI_Finalize();
}
