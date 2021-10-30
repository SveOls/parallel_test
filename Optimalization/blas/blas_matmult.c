#include <stdio.h>
#include <stdlib.h>
#include <cblas.h>
#include <time.h>
#define AVAL 3.0
#define BVAL 5.0

int main()
{

    time_t t1,t2;

    double *A, *B, *C;
    int m, n, k, i, j;
    double alpha, beta;
    int size=5000;
    m = size, k = size, n = size;

    alpha = 1.0; beta = 0.0;

    A = (double *)malloc( m*k*sizeof( double ));
    B = (double *)malloc( k*n*sizeof( double ));
    C = (double *)malloc( m*n*sizeof( double ));

    for (i = 0; i < (m*k); i++) {
        A[i] = AVAL;
    }

    for (i = 0; i < (k*n); i++) {
        B[i] = BVAL;
    }

    for (i = 0; i < (m*n); i++) {
        C[i] = 0.0;
    }
 
    t1=clock();    

    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, 
                m, n, k, alpha, A, k, B, n, beta, C, n);
    
    t2=clock();

    printf("Time %f\n",(double)(t2-t1)/CLOCKS_PER_SEC);


    free(A);
    free(B);
    free(C);
  
    return 0;
}
