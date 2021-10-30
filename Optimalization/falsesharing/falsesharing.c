#include <stdio.h>
#include <malloc.h>
#include <time.h>

int main (int argc, char *argv[])
{
    time_t t1,t2;

    int i,j;
    int n=10000;
    //double A[n][n];
    //double B[n][n];
    // INIT
    double **A = (double**) malloc(sizeof(double*)*n);
    double **B = (double**) malloc(sizeof(double*)*n);
    for (i=0;i<n;i++)
    {
        A[i] = (double*) malloc(sizeof(double)*n);
        B[i] = (double*) malloc(sizeof(double)*n); 
    }
    for (i=0;i<n;i++)
        for (j=0;j<n;j++)
        {
            A[i][j] = (double) (i+j);
            B[i][j] = 0.0;
        }


    t1=clock();
    // CALC
    for (i=0;i<n;i++)
       for (j=0;j<n;j++)
           B[j][i] = A[j][i]*A[j][i];

    t2=clock();

    printf("Time %f\n",(double)(t2-t1)/CLOCKS_PER_SEC);
    free(A);
    free(B);
    return 0;

}
