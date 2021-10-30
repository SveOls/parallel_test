#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
int main(int argc, char *argv[])
{
   int i,t;
   int n=1000000;
   int T=5000;
   time_t t1,t2;
      
   // double A[n],B[n],C[n];
   double * A = (double*) malloc (sizeof(double)*n);
   double * B = (double*) malloc (sizeof(double)*n);
   double * C = (double*) malloc (sizeof(double)*n);

   //Init  
   for (i=0;i<n;i++) 
   {
      A[i]=i;
      B[i]=i*2.0;
   }
  
   t1=clock();
   for (t=0;t<T;t++)
      for (i=0;i<n;i++)
         C[i]+=A[i]*B[i];
   t2=clock();

   printf("Time %f\n",(double)(t2-t1)/CLOCKS_PER_SEC);
   
     
}
