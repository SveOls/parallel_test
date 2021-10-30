gfortran -c -O3 helloworld.f90 -fopenmp
gfortran -o output helloworld.o -fopenmp
export OMP_NUM_THREADS=8
./output