program helloworld



    implicit none

    integer::omp_get_thread_num
    integer::omp_get_num_threads

! starts a parallel block
    !$omp parallel
! only one thread may enter this zone
    !$omp master
    write(6,*) omp_get_num_threads(), omp_get_thread_num()
    !$omp end master
! all threads wait until the master thread is done with its print, ensuring that no code below this point is run before it's done
    !$omp barrier
    write(6,*)'Hello world from thread', omp_get_thread_num()
    !$omp end parallel

end program helloworld
