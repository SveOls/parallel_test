#include "omp.h"
#include <stdio.h>

int main (int argc, char *argv[])
{

    //Create two sections.    
    printf("Hello world from thread no %d\n",omp_get_thread_num());

    printf("Hello world from thread no %d\n",omp_get_thread_num());
}
