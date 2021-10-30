#include <stdio.h>
#include <time.h>
int main()
{
  //Program: Calculation of PI.
  int i;
  double x, mypi,sum=0.0;
  double vpi = 3.141592654;
  double tol = 0.0000001;
  long nsteps = 1000000000;//Try different nsteps
  double step,diff,wend;
  time_t t1,t2;

  t1=clock();
 
  step = 1.0/ (double) nsteps;
   
  for(i=0;i<nsteps;i++)
  {
    x = (i + 0.5) * step;
    sum += 4.0/(1.0 + x * x);
  }
  
  mypi = step * sum;

  t2=clock();

  printf("Time %f\n",(double)(t2-t1)/CLOCKS_PER_SEC);

  diff = mypi-vpi;
  if (diff<0) diff *=-1.0;

  if (diff>tol)
    printf("Error in pi: %f\n",mypi);
  else
    printf("PI %1.10f\n", mypi);

}
