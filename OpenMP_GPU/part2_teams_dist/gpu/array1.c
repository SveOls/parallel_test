#include "omp.h"
#include <stdio.h>
int main(int argc , char **argv) 
{

  int i;
  int sum=0;
  double w0;
  int n=1000000000;
  double A[n];
  int t=0;

  w0=omp_get_wtime();

  // Init data
  for (i=0;i<n;i++)
	A[i]=3.0; 
 

  // Calculation: Output is sum
  while(t<3)
  {
     for (i=0;i<n;i++)
        sum = sum + (int) A[i];
     
     t++;
  }
  
  if (sum !=  (3*3*n)) 
    printf("Wrong sum %d. Expeced %d\n",sum,3*3*n);
  else
    printf("Correct result\n");
 
  printf("Run time %f\n",omp_get_wtime()-w0);

  return 0;   
	
}
