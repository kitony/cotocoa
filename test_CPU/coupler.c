#include <stdio.h>
#include <mpi.h>
#include "ctca.h"
#include <stdlib.h>

int main()
{
    CTCAC_init();
    CTCAC_buffer_init();
    //MPI_Barrier(MPI_COMM_WORLD);
    CTCAC_buffer_free();
    CTCAC_finalize();
}
