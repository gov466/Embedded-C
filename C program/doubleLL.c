/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include<stdlib.h>
struct linkedlist{
    int data;
    struct linkedlist *next;
    struct linkedlist *prev;
}*head=NULL,*tail=NULL;
typedef struct linkedlist node_t;

node_t *create(void)
{
    node_t *node;
    node= malloc(sizeof(struct linkedlist));
    printf("enter data");
    scanf("%d",&node->data);
    if((head==NULL)&&(tail==NULL))
    {
    head=node;
    tail=node;
    head->next=NULL;
    head->prev=NULL;
    }
    else
    {
        tail->next=node;
        node->prev=tail;
        node->next=NULL;
        tail=node;
    }
}
node_t *addnode()






int main()
{
    int n;
    printf("1.create" );
    scanf("%d",&n);
    while(1)
    {
    switch(n)
    {
        case 1: create();
            break;
        default:
        printf("\n Wrong choice menu");
    }
    }
    return 0;
}
