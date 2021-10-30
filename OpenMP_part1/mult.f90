program mult
implicit none
  !! Program matrix multiplication; C = AB ,
  !! where A is mxn, and B is nxp and C is A mxp matrix
  integer::i,j,k
  real:: tmp
  integer::m,n,p,size
  real::aval,bval,tol

  real, allocatable, dimension (:,:):: A,B,C
  real:: cval,err,errsq
  real(8)::wstart
  real(8)::omp_get_wtime
  integer:: omp_get_num_threads, omp_get_thread_num

  aval=3.0
  bval=5.0
  tol =0.001
  size = 2000
  m=size
  n=size
  p=size

  allocate (A(n,p))
  allocate (B(p,m))
  allocate (C(n,m))

  ! Init A,B and C matrices
  A(:,:)=aval
  B(:,:)=bval
  C(:,:)=0.0

  wstart = omp_get_wtime();

  ! Calculate the C matrix
  !$omp parallel do private(tmp)
  do i=1,n
    do j=1,m
      tmp=0.0
      do k=1,p
        tmp = tmp + A(i,k) * B(k,j)
      end do
      C(i,j)=tmp
    end do
  end do
  !$omp end parallel do

  write(6,*) 'time ',omp_get_wtime()-wstart

  ! Error check
  cval = p * aval* bval
  errsq = 0.0

  do i=1, n
    do j=1, m
      err = C(i,j) - cval;
      errsq = errsq + err*err;
    end do
  end do

  if(errsq > tol) then
    write(6,*)'Error in the multiplication:' ,errsq
  else
    write(6,*)'It works'
  end if

  deallocate(A)
  deallocate(B)
  deallocate(C)

end program mult
