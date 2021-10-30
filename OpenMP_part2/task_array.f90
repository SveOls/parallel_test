program task_array
    implicit none
    integer, parameter :: n=20
    integer :: i
    integer, dimension (n) :: array

    ! Init
    do i=1,n
       array(i)=0
    end do

    !Use openmp task
    !$omp parallel
    !$omp task
    i=1
    do while (i<=n)

       array(i)=i

       i=i+1

    enddo
    !$omp end task


    !$omp single
    !$omp taskwait
    ! Display array
    do i=1,n
        write(*,*) array(i)
    enddo

    !$omp end single
    !$omp end parallel


end program task_array
