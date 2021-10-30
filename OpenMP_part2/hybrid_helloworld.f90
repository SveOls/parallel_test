program helloworld 
implicit none
include 'mpif.h'  
   integer :: omp_get_thread_num , omp_get_num_threads 
   integer :: myrank,ranks
   integer :: ierr
   call MPI_INIT(ierr)
   call MPI_COMM_SIZE(MPI_COMM_WORLD,ranks,ierr)
   call MPI_COMM_RANK(MPI_COMM_WORLD,myrank,ierr)

   write(6,*) 'Hello world'

   call MPI_FINALIZE(ierr)

end program helloworld

