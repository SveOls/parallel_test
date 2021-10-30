#include "omp.h"
#include <stdlib.h>
#include <stdio.h>

int main (int argc, char *argv[])
{
    int i=10;
    
    // Create a task inside this while loop
    while (i<10)
    {
    	printf("Hello world from thread %d and iteration %d\n",omp_get_thread_num() , i);
	i--;
    }      

    printf("Hello world finished!\n");
        
    	
    return 0;
}
