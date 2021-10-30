#include "omp.h"
#include <stdio.h>
int main(int argc , char **argv) 
{

  int i;
  int t;
  int sum=0;
  double w0;
  int n=1000000000;
  double A[n],B[n];
  double tmp;
  w0=omp_get_wtime();


  // Init data
  for (i=0;i<n;i++)
  {
	A[i]=3.0;
        B[i]=0.0;
  }

  // Calculation: Outputs are sum and B
  t=0;
  while(t<3)
  { 
     for (i=0;i<n;i++)
     {
        tmp  = A[i] * t;
	B[i] = B[i] + tmp;
     } 
     t++;
  }
  
  for (i=0;i<n;i++)
     sum  = sum + (int) B[i];

  if (sum !=  410065408) 
    printf("Wrong sum %d. Expeced %d\n",sum,3*3*n);
  else
    printf("Correct result\n");

  if (B[10] != 9) 
     printf("Wrong content of B [10] %f. Expected 30\n", B[10]);
  
  printf("Run time %f\n",omp_get_wtime()-w0);

  return 0;   
	
}
