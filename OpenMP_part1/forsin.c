#include "omp.h"
#include <stdio.h>
#include <math.h>
#include <malloc.h>
int main ()
{
  
  long i;
  long n=100000000;

  //double X[n],Y[n];  
  double *X=(double*) malloc(sizeof(double)*n);
  double *Y=(double*) malloc(sizeof(double)*n);  

  //Init X
  for (i=0;i<n;i++)
    X[i]=(double)i;

  double wstart = omp_get_wtime();
 
  //Calc y
  for (i=0;i<n;i++)
    Y[i]= sin( X[i]) + cos(X[i]);
    
  printf("Time %f\n",omp_get_wtime()-wstart);

  free(X);
  free(Y);

}
