
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
//main function starts
int main()
{
    int choice;
    q.rear=-1;  //setting initial value as empty
    q.front=-1;
      

    while (1)     //infinite loop

    {
         printf("==============================================");
 
         printf("\n\n****IMPLEMENTATION OF QUEUE USING POINTERS****\n");
 
         printf("==============================================");
 
                    printf("\n\t\t  MENU\n");
 
         printf("==============================================");
   
        printf("\n\t1.Insert element to queue \n");

        printf("\t2.Delete element from queue \n");

        printf("\t3.Display all elements of queue \n");

        printf("\t4.Quit \n");

        printf("\tEnter your choice : ");

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
/*adding elements to queue */
void enqueue()
{
 if(q.rear==MAX-1)  //checking if queue is full
 {
     printf("\n\n\t queue overflow...");
     
 }
 else   //if queue is not full
 {
   int item;
   printf("\n\n\t Enter the data item :");  //adding atem to queue
   scanf("%d",&item);
   
   if(q.rear==-1 && q.front==-1)
   {
       q.rear++;    //pointing front and rear values to 0th posisition in queue
       q.front++;
       q.que[q.rear]=item;  //setting the first element in queue
   }
   else
   {
       q.rear++;    //if already elements are present the increment the rear
       q.que[q.rear]=item;  //add elements to next posistion
   }
 }
}
/* removing element from queue*/
void dequeue()
{
 int item;
 if(q.front==-1)    //checking if queue is empty
 {
     printf("\n\n\t queue underflow..");
     
 }
 else
 {
     item=q.que[q.front];   //if queue is not empty taking the first inserted element
     printf("\n\n\t The deleted elemnt =%d",item);
     if(q.front==q.rear)    //
     {
         q.front=-1;
         q.rear=-1;
     }
     else
     {
         q.front++; //if elemnt is removed changing the posistion of front 
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
