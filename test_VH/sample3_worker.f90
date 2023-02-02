program sample_worker
  use mpi
  use ctca
  implicit none

  integer(kind=4) :: dataintnum, myrank, nprocs, ierr, areaid, progid, fromrank
  integer(kind=4) :: world_myrank
  integer(kind=4),dimension(2) :: dataint
  real(kind=8),dimension(6,400) :: datareal8
  character(len=256) :: fname
  integer(kind=4) :: j, k, c
  integer(kind=8) :: s
  s = 6*400
  
  call CTCAW_init(1, 2)
  print *, "worker1 init done"

  call MPI_Comm_size(CTCA_subcomm, nprocs, ierr)
  call MPI_Comm_rank(CTCA_subcomm, myrank, ierr)
  call MPI_Comm_rank(MPI_COMM_WORLD, world_myrank, ierr)

  call CTCAW_regarea_real8(areaid)

  do while (.true.)
     call CTCAW_pollreq_withreal8(fromrank, dataint, 2, datareal8, s)
     c = dataint(2)

     if (CTCAW_isfin()) then
        exit
     end if

     print *, world_myrank, "worker1 poll req done ", c, fromrank

     ! set up data
     call MPI_Bcast(datareal8, 6*400, MPI_DOUBLE_PRECISION, 0, CTCA_subcomm, ierr)
     print *, world_myrank, "worker1 bcast done"

     do j = 1, 400
        do k = 1, 6
           if (datareal8(k, j) /= c*10000 + j*10 + k) then
              print *, 'Worker wrong result: ', c, j, k, datareal8(k, j) , c*10000 + j*10 + k
           end if
        end do
     end do

     ! do work
     do j = 1, 400
        do k = 1, 6
           datareal8(k, j) = datareal8(k, j) * 10.0
        end do
     end do

     if (myrank == 0) then
        call CTCAW_writearea_real8(areaid, fromrank, (dataint(2) - 1) * 6 * 400, 6*400, datareal8)
     end if

     ! end this work
     call CTCAW_complete()
     print *, world_myrank, "worker1 complete done"
  end do

  call CTCAW_finalize()

end program sample_worker
