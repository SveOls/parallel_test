program array1
implicit none
  
integer:: i,n,t
integer::sum
real(8):: w0
real(8):: omp_get_wtime
real(8),allocatable, dimension (:)::A
 

  n=1000000000
  
  allocate(A(n))  

  w0=omp_get_wtime()

  !Init data
  do i=1,n
     A(i)=3.0
  end do 
  t=0
  ! Calculation: Output is sum
  do while (t < 3)
     do i=1,n
        sum = sum + int(A(i))
     end do
     t=t+1
  end do
  
  if (sum .ne.  (3*3*n)) then 
    write(6,*) 'Wrong sum ',sum
    write(6,*) 'Expeced ',3*3*n
  else
    write(6,*) 'Correct result'
  end if
 
  write(6,*) 'Run time ',omp_get_wtime()-w0

  deallocate(A)
	
end program array1
