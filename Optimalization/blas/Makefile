all: blas_matmult matmult
blas_matmult: blas_matmult.c
	gcc -O3 -lopenblas -o blas_matmult blas_matmult.c -lm
matmult: matmult.c
	gcc -O3 -o matmult matmult.c
clean:
	rm -f blas_matmult matmult
