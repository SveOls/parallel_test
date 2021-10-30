program sections
implicit none
   integer :: i,j,N
   real(8) :: sum,pi
   real(8) :: wstart, omp_get_wtime
   N=20000
   pi=3.141592654

   wstart=omp_get_wtime()
   !! Summation ( sin(2*pi*(i+j)) + cos(2*pi*(i+j)) )

   !!  Create two sections of the summation
   !$omp parallel default(none) private(i,j) firstprivate(N, pi) reduction(+:sum)
   sum = 0
   !$omp sections
   !$omp section
   do i=0,N-1
      do j=0,N-1
         sum = sum + sin (2*pi*(i+j))
      end do
   end do

   !$omp section
   do i=0,N-1
      do j=0,N-1
         sum = sum + cos (2*pi*(i+j))
      end do
   end do
   !$omp end sections
   !$omp end parallel

   write(6,*) 'sum= ',sum
   write(6,*) 'Time= ',omp_get_wtime()-wstart

end program sections


