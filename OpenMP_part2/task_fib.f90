program fib
implicit none
    integer :: n
    integer(4) :: result

    n=30

    !! Recursive 
    result = rec_fib (n)
    write(6,*) 'Result ',result

    if (result /= seq_fib(n) ) then
        write(6,*) 'Result is wrong. Correct result is !',seq_fib(n)
    end if

  contains

    !! Sequential fibonacci -------------------------
    function seq_fib (n)

    implicit none
    integer, intent(in) :: n
    integer(4)          :: seq_fib
    integer(4)          :: fn,fn1,fn2
    integer             :: i

    fn2=0;
    fn1=1;

    do i=2,n

        fn=fn1+fn2;
        fn2=fn1;
        fn1=fn;
    end do

    seq_fib =fn
    end function seq_fib


    !! Recursive fibonacci ---------------------------------
    recursive function rec_fib (n) result(res)
    implicit none
    integer, intent(in) :: n
    integer(4)          :: res
    integer(4)          :: fn,fn1,fn2


    if ( (n==0) .or. (n==1) ) then
        res = n
        return
    end if

    fn1 = rec_fib (n-1)
    fn2 = rec_fib (n-2)

    fn = fn1 + fn2

    res = fn

    end function rec_fib



end program fib
