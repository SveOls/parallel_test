#include "omp.h"
#include <stdio.h>
int main()
{
  //Program: Calculation of PI.
  int i;
  double x, mypi,sum=0.0;
  double vpi = 3.141592654;
  double tol = 0.00001;
  long nsteps = 1000000000;//Try different nsteps
  double step,diff,wend;
  
  double wstart = omp_get_wtime();
  
  step = 1.0/ (double) nsteps;
   
  for(i=0;i<nsteps;i++)
  {
    x = (i + 0.5) * step;
    sum += 4.0/(1.0 + x * x);
  }
  
  mypi = step * sum;
  wend = omp_get_wtime();

  diff = mypi-vpi;
  if (diff<0) diff *=-1.0;

  if (diff>tol)
    printf("Error in pi: %f\n",mypi);
  else
    printf("PI %1.10f\n", mypi);
  printf("Time: %f\n",wend-wstart );

}
