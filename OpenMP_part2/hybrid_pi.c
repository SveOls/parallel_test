#include "omp.h"
#include "mpi.h"
#include <stdio.h>
#define MASTER_RANK 0
int main(int argc, char *argv[])
{
   //Program: Calculation of PI.
   long i,istart,iend;
   double x, mypi, sum=0.0, lsum=0.0;
   double vpi = 3.141592654;
   double tol = 0.00001;
   long   nsteps = 3000000000;//Try different nsteps
   double step,diff;
   double starttime;
   int myrank,ranks;
  
   MPI_Init(&argc,&argv);
   MPI_Comm_size(MPI_COMM_WORLD,&ranks);
   MPI_Comm_rank(MPI_COMM_WORLD,&myrank);

   starttime = MPI_Wtime();

   step = 1.0/ (double) nsteps;

   // Set start and end value for loop interation for its rank 
   istart = myrank * nsteps / ranks;
   iend   = (myrank+1) * nsteps / ranks;
   for(i=istart;i<iend;i++)    // Squential for(i=0;i<nsteps;i++)
   {
      x = (i + 0.5) * step;
      lsum += 4.0/(1.0 + x * x);
   }
   
   // Reduction of all lsum to sum with operator +
   MPI_Reduce(&lsum,&sum,1,MPI_DOUBLE,MPI_SUM,MASTER_RANK,MPI_COMM_WORLD);

   mypi = step * sum;

   if (myrank == MASTER_RANK)
   {

      diff = mypi-vpi;
      if (diff<0) diff *=-1.0;

      if (diff>tol)
         printf("Error in pi: %f\n",mypi);
      else
         printf("PI %1.10f\n", mypi);

      printf(" Runtime : %f\n",MPI_Wtime()-starttime);
   }


   MPI_Finalize();

}

