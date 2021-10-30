#include "omp.h"
#include <stdio.h>
#include <malloc.h>
int main (int argc, char *argv[])
{
    int i=0;
    int n=20;

    //int array[n];
    int *array =(int*) malloc(sizeof(int)*n);
    // Init
    for (i=0;i<n;i++) array[i]=0;

    //Use openmp task
    i=0; 
    while (i<n)
    {
       array[i]=i;

       i++;

    }

    // Display array   
    for (i=0;i<n;i++) printf("array %d\n",array[i]);

}

