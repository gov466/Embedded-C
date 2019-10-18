#include <stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 5
void enqueue();
void display();
void dequeue();
//q structure hold all variables
struct queue
{
    int front;  //holds value of front position
    int rear;   //holds value of rear position
    int que[MAX];
}q;
int main()
{
    int choice;
    q.rear=-1;
    q.front=-1;
      

    while (1)     //infinite loop

    {

        printf("1.Insert element to queue \n");

        printf("2.Delete element from queue \n");

        printf("3.Display all elements of queue \n");

        printf("4.Quit \n");

        printf("Enter your choice : ");

        scanf("%d", &choice);

        switch (choice)   //switch case statement for different functions

        {

            case 1:

            enqueue();  //calling function for inserting element

            break;

            case 2:

            dequeue();  //calling function for deleting element

            break;

            case 3:

            display();  //calling function for display

            break;

            case 4:

            exit(0);

            default:

            printf("Wrong choice \n");

        } /* End of switch */

    } /* End of while */

} /* End of main() */

void enqueue()
{
 if(q.rear==MAX-1)
 {
     printf("\n\n\t queue overflow...");
     
 }
 else
 {
   int item;
   printf("\n\n\t Enter the data item");
   scanf("%d",&item);
   
   if(q.rear==-1 && q.front==-1)
   {
       q.rear++;
       q.front++;
       q.que[q.rear]=item;
   }
   else
   {
       q.rear++;
       q.que[q.rear]=item;
   }
 }
}

void dequeue()
{
 int item;
 if(q.front==-1)
 {
     printf("\n\n\t queue underflow..");
     
 }
 else
 {
     item=q.que[q.front];
     printf("\n\n\t The deleted elemnt =%d",item);
     if(q.front==q.rear)
     {
         q.front=-1;
         q.rear=-1;
     }
     else
     {
         q.front++;
     }
     
 }
}
void display()
{
    int i;
    if(q.front == -1)
    {
        printf("\n\n\t the queue is empty");
    }

    else
    {
        printf("\n\n\t the elements in the queue are as follows");
        for(i=q.front;i<=q.rear;i++)
        {
            printf("\n %d\n",q.que[i]);
        }
    }
    
}
