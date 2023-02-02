program sample_worker
  use mpi
  use ctca
  implicit none

  integer(kind=4) :: dataintnum, myrank, nprocs, ierr, areaid, progid, fromrank
  integer(kind=4) :: world_myrank
  integer(kind=4),dimension(2) :: dataint
  real(kind=8),dimension(6,400) :: datareal8
  character(len=256) :: fname
  integer(kind=4) :: i, j, c
  integer(kind=8) :: s
  s = 6*400
  
  call CTCAW_init(2, 2)
  print *, "worker2 init done"

  call MPI_Comm_size(CTCA_subcomm, nprocs, ierr)
  call MPI_Comm_rank(CTCA_subcomm, myrank, ierr)
  call MPI_Comm_rank(MPI_COMM_WORLD, world_myrank, ierr)

  do while (.true.)
     call CTCAW_pollreq_withreal8(fromrank, dataint, 2, datareal8, s)
     c = dataint(2)

     if (CTCAW_isfin()) then
        exit
     end if

     ! set up data
     call MPI_Bcast(datareal8, 6*400, MPI_DOUBLE_PRECISION, 0, CTCA_subcomm, ierr)

     ! do work
     write(fname, '("out2.", i3.3,"-", i3.3, ".txt")') c, myrank
     open (10, file=fname, status="replace")
     do i = 1, 400
        write(10, *) datareal8(1:6, i)
     end do
     close(10)

     ! end this work
     call CTCAW_complete()
     print *, world_myrank, "worker2 complete done"

  end do

  call CTCAW_finalize()

end program sample_worker
