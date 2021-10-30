program task_helloworld
!implicit none

    integer :: i
    integer :: omp_get_thread_num
    integer  :: ret 
    i=20

    do while (i>0)
       ret=hello_world(i) 
       i=i-1
    end do

end program task_helloworld


subroutine hello_world(iter)
    implicit none
    integer, intent(in) :: iter
      
    integer :: omp_get_thread_num
     
     write(6,*) 'Hello world from thread and iteration ',omp_get_thread_num()
end subroutine hello_world


