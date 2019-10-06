//create a single linked list to enter the elements and find largest number

#include <stdio.h>
#include <stdlib.h>

struct node     //linked list node
{
    int data;
    struct node *next;
}*head=NULL,*temp,*temp1;
void create();
void insert();
void display();
void largest();
int count=0;
 main()     //main function
{
    while(1)
    {
    int  n;
    printf("\n1.Create\n 2.Display\n  4.Exit\n 5.Exit\n");
    scanf("%d",&n);
    switch(n)       //case statement for different options
    {
        case 1: create();
                break;
        case 2: display();
                break;
        case 4: largest();
                 break;
        case 5: exit(0);

    }
    }
}
    void create()   //function for creating node
    {

      temp=malloc(sizeof(struct node));     //allocating dynamic memmory for new node
      printf("enter data");             //entering data
      scanf("%d",&temp->data);
      if(head==NULL)            //checking if head is having pointer null
      {
          head=temp;
          head->next=NULL;
      }
      else      //if not creating new node
      {
          for(temp1=head;temp1->next!=NULL;temp1=temp1->next);
          temp1->next=temp;
          temp->next=NULL;
      }
    count++;        //increasing value of count to display node number
    }
        void display()      //function to display node
    {

      for(temp1=head;temp1!=NULL;temp1=temp1->next)
      {
          printf("%d  ",temp1->data);

      }
    }
    void largest()      //function to  find largest value
    {
        int max=temp->data;
        while(temp!=NULL)
        {
            if( (temp->data) > max )
            {
                max=temp->data;
            }
            temp=temp->next;
        }
        printf("max value is: %d",max);

    }
