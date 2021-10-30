#include "omp.h"
#include <stdio.h>
#include <malloc.h>
#define AVAL 3.0
#define BVAL 5.0
#define TOL 0.001

// Program: Matrix multiplication C=AB,
// where A is mxn, B is nxp and C is mxp matrix.

int main(int argc,char *argv[])
{
  
  int i,j,k;

  double tmp=0.0;

  int size = 2000; //Try different sizes
  int n = size;
  int m = size; 
  int p = size;
  
 // double A[n][p];
 // double B[p][m];
 // double C[n][m];
  //Dynamic memory allocation
  double **A = (double**) malloc(sizeof(double*)*n);
  double **B = (double**) malloc(sizeof(double*)*p);
  double **C = (double**) malloc(sizeof(double*)*n);
  for (i=0;i<n;i++)
  {
     A [i] = (double*) malloc(sizeof(double)*p);
     C [i] = (double*) malloc(sizeof(double)*m);
  }
  for (j=0;j<p;j++)
    B [j] = (double*) malloc(sizeof(double)*m);
 

  double cval,err,errsq;

  /*Init A,B and C matrices*/
  for (i=0;i<n;i++)
    for (j=0;j<p;j++)
      A[i][j] = AVAL;

  for (j=0;j<p;j++)
    for (k=0;k<m;k++)
      B[j][k] = BVAL;

  for (i=0;i<n;i++)
    for (j=0;j<m;j++)
      C[i][j] = 0.0;
 
  
  double wstart = omp_get_wtime();

  /*Calculate the C matrix  (Something to do here?)*/
  
 for (i=0;i<n;i++)
  {
    for (j=0;j<m;j++)
    {

      tmp=0.0;
      for (k=0;k<p;k++)
      {
	 tmp += A[i][k] * B[j][k];
      }
      C[i][j]=tmp;    
  
    }
  }

  printf("time %f\n",omp_get_wtime()-wstart);

  /* Error check*/
  cval = p * AVAL* BVAL;
  errsq = 0.0;

  for(i=0;i<n;i++)
    for (j=0;j<m;j++)
    {
      err = C[i][j]-cval;
      errsq += err*err;
    }

  if(errsq > TOL)
    printf("\n Error in the multiplication: %f\n",errsq);
  else
    printf("\n Its work %f\n",cval);
  return 0;
}
