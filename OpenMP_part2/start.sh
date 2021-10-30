gfortran -c -O3 task_linkedlist.f90 -fopenmp
gfortran -o output task_linkedlist.o -fopenmp
export OMP_NUM_THREADS=8
./output