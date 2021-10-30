#include "mpi.h"
#include "omp.h"
#include <stdlib.h>
#include <stdio.h>

#define MASTER 0 //Master process 
  
int main (int argc, char * argv[])
{
	int myrank,ranks;
	
	MPI_Init(&argc,&argv);
	MPI_Comm_size(MPI_COMM_WORLD,&ranks);
	MPI_Comm_rank(MPI_COMM_WORLD,&myrank);

	printf("Hello world\n");

	MPI_Finalize();

	return 0;
}

