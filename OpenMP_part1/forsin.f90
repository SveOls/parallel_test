program forsin

real, allocatable, dimension(:) :: X, Y
integer(8)  :: i, n
real(8)     :: wstart
real(8)     :: omp_get_wtime

real        :: tmp

n=1000000000

allocate(X(n))
allocate(Y(n))

!Init X
!$omp parallel do
do i=1,n
   X(i)=i-1
end do
!$omp end parallel do

wstart = omp_get_wtime()

!Calc y
!$omp parallel do
do i=1,n
   Y(i) = sin( X(i) ) + cos( X(i) )
end do
!$omp end parallel do

write (6,*)'Time: ', omp_get_wtime()-wstart
deallocate(X)
deallocate(Y)

end program forsin
