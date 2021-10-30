program array2
  integer::i,t,n,sum
  real(8):: tmp
  real(8):: w0
  real(8)::omp_get_wtime
  real(8), allocatable,dimension(:)::A,B
  sum=0
  n=1000000000

  allocate( A(n))
  allocate( B(n))

  w0=omp_get_wtime()


  ! Init data
  do i=1,n
     A(i)=3.0
     B(i)=0.0
  end do

  ! Calculation: Outputs are sum and B
  t=0
  do while(t<3)
  
     do i=1,n
        tmp  = A(i) * t
        B(i) = B(i) + tmp
     end do 
     t=t+1
  end do
  
  do i=1,n
     sum  = sum + int(B(i))
  end do

  if (sum .ne.  410065408) then 
    write(6,*) 'Wrong sum ', sum
    write(6,*) 'Expeced ',(3*3*n)
  else
    write(6,*) 'Correct result'
  end if

  if (B(10) .ne. 9) then
     write(6,*) 'Wrong content of B. Expected 30. Your B[10] is ',B(10)
  end if  
  write(6,*) 'Run time ', omp_get_wtime()-w0

  deallocate(A)
  deallocate(B) 

end program array2
