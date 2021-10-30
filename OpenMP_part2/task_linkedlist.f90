program linkedlist
implicit none

    type node
      integer :: i
      type (node) , pointer :: child
    end type node

    type (node) , pointer :: list,p,tmp
    integer, parameter    :: n=10
    integer :: omp_get_thread_num

    list => create_list(n)

    ! Add parallel tasks here. Hint: The pointer p must be set as private inside
    ! the parallel region
    !$omp parallel
    !$omp single private(p)
    p => list
    do while (associated(p))  !Do loop until list is empty
        !$omp task
        write(*,*) 'i ',p%i, 'thread: ', omp_get_thread_num()
        !$omp end task
        p => p%child

    end do
    write(*,*) 'Finished'
    !$omp end single
    !$omp end parallel

    !Deallocate (do nothing here)
    p => list
    do while (associated(p))
        tmp => p%child
        deallocate(p)
        p=>tmp
    end do

contains

!  Create a linked list
!  (Don't do anything here)
function create_list ( n )

    implicit none
    type (node) , pointer :: create_list
    integer , intent (in) :: n
    integer , target :: i
    type (node), pointer  :: head,tmp,p

    nullify (create_list)
    if (n .eq. 0) then
        return
    end if
    allocate(head)
    i=1
    p=>head
    p%i=i
    do i=2, n
        allocate (tmp)
        tmp%i = i
        p%child => tmp
        p => tmp
    end do
    nullify (p%child)
    create_list => head

end function create_list
end program linkedlist
