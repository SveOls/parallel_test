program sec_helloworld
implicit none
    integer :: thread_no
    integer :: num_threads
    integer :: omp_get_thread_num
    integer :: omp_get_num_threads



    !! Create two sections.
    !$omp parallel

    !$omp master
    write(6,*) 'number of threads: ',omp_get_num_threads()
    !$omp end master

    !$omp sections
    !$omp section
    write(6,*) 'Section 1: Hello world from thread no ',omp_get_thread_num()
    !$omp section
    write(6,*) 'Section 2: Hello world from thread no ',omp_get_thread_num()
    !$omp section
    write(6,*) 'Section 3: Hello world from thread no ',omp_get_thread_num()
    !$omp section
    write(6,*) 'Section 4: Hello world from thread no ',omp_get_thread_num()
    !$omp end sections

    !$omp end parallel

end program sec_helloworld
