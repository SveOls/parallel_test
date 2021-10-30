#include "omp.h"
#include <stdlib.h>
#include <stdio.h>

struct snode
{
    struct snode *child;
    int i;
};

typedef struct snode node;

node* init_list(int n)
{
    node *head = NULL;
    
    if (n==0)
        return head;

    head = (node*) malloc(sizeof(node));
    node *tmp = NULL;
    node *p = head;
    int i;

    p->i=0;
    for (i=1;i<n;i++)
    {
        tmp = (node*) malloc (sizeof(node));
        tmp->i = i;
        p->child = tmp;
        p=tmp;
    }
    p->child = NULL;
    return head;
}


int main (int argc, char *argv[])
{
    int i;
    int n=10;

    node *list = init_list(n);
   	
    while (list != NULL)
    {
      printf("thread %d list->i %d\n",omp_get_thread_num(),list->i);

      list = list->child;
   
    }
    
    return 0;
}
