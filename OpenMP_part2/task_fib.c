#include "omp.h"
#include <stdlib.h>
#include <stdio.h>

//Sequential fibonacci
long seq_fib(int n)
{

     long fn,fn1,fn2;
     long tmp;
     int i;
     fn2=0;
     fn1=1;
     fn=0;

     for (i=2;i<=n;i++)
     {
        fn=fn1+fn2;
        fn2=fn1;
        fn1=fn;
     }
     return (fn);
}

//Recursive fibonacci 
long rec_fib(int n)
{
    long fn, fn1, fn2 , fn3, fn4;
    if ( (n==0) || (n==1) ) return n;

    fn1 = rec_fib (n-1);
    fn2 = rec_fib (n-2);

    fn = fn1 + fn2 ;

    return fn;
}

int main( int argc, char *argv[])
{
    int n = 10;

    long result,correct;

    result = rec_fib (n);

    printf("Result %ld\n",result);

    correct = seq_fib(n);
    if (result != correct )
        printf("Result is wrong! Correct result is %ld\n", correct ); 

    return 0;
}

