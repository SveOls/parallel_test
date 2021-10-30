#include "omp.h"
#include <stdio.h>
#include <math.h>

int main (int argc, char *argv[])
{
    int i,j;
    
    double sum;
    double pi = 3.141592654;
    int    N  = 20000;
    double wstart = omp_get_wtime();
 
    // Summation sin(2*pi*(i+j)) + cos(2*pi*(i+j))
  
    // Create two sections of the sumation
    sum = 0;
     
    for (i=0;i<N;i++)
       for (j=0;j<N;j++)
	sum += sin (2*pi*(i+j));
   
    for (i=0;i<N;i++)
       for(j=0;j<N;j++)
        sum += cos(2*pi*(i+j));
  	
    printf("sum %f time %f\n",sum,omp_get_wtime()-wstart);
 
}


