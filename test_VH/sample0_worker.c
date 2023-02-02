#include <stdio.h>
#include <mpi.h>
#include "ctca.h"

int main()
{
    CTCAW_init(0, 2);

    CTCAW_finalize();
}
