program pi
implicit none
!!Program; Calculation of PI
integer::i
real(8)::sum,x,mypi,vpi,step,tol,rnsteps
integer(4)::nsteps
real(8)::wstart,wend
real(8)::omp_get_wtime

nsteps = 1000000000 !Try diffent nsteps
rnsteps = nsteps
tol = 0.00001
vpi = 3.141592654

wstart = omp_get_wtime()

step = 1.0/ rnsteps
sum = 0

!$omp parallel do default(none) private(x) firstprivate(step, nsteps) reduction(+:sum)
do i=0,nsteps-1
   x = (i+0.5) * step
   sum = sum + 4.0 / (1.0 + x * x)
end do
!$omp end parallel do

mypi = step * sum
wend = omp_get_wtime()

if ( abs(mypi-vpi) > tol) then
   write(6,*) 'Error in PI!: ',mypi
else
   write(6,*) 'PI=', mypi
end if

write(6,*)'Time: ',wend-wstart

end program pi
