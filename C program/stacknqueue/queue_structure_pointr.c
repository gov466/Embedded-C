
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
    int head;  //holds value of front position
    int tail;   //holds value of rear position
    int arr[MAX];
}q;
//main function starts
int main()
{
    int ch;
    q.tail=-1;  //setting initial value as empty
    q.head=-1;
      

    while (1)     //infinite loop

    {
         printf("\t##############################################");
 
         printf("\t\n\n\t $$$$ QUEUE IMPLEMENTATION USING POINTERS $$$$\n");
 
         printf("\t----------------------------------------------");
 
                    printf("\n\t\t\t LIST \t\t\n");
 
         printf("\t##############################################");
   
        printf("\n\t\t1.Insert element  \n");

        printf("\t\t2.Delete element  \n");

        printf("\t\t3.Display elements \n");

        printf("\t\t4.End \n");

        printf("\t\tEnter any of number above : ");

        scanf("%d", &ch);

        switch (ch)   //switch case statement for different functions

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

            printf("Wrong number \n");

        } /* End of switch */

    } /* End of while */

} /* End of main() */
/*adding elements to queue */
void enqueue()
{
 if(q.tail==MAX-1)  //checking if queue is full
 {
     printf("\n\n\t queue is full...");
     
 }
 else   //if queue is not full
 {
   int data;
   printf("\n\n\t Enter the element :");  //adding atem to queue
   scanf("%d",&data);
   
   if(q.tail==-1 && q.head==-1)
   {
       q.tail++;    //pointing front and rear values to 0th posisition in queue
       q.head++;
       q.arr[q.tail]=data;  //setting the first element in queue
   }
   else
   {
       q.tail++;    //if already elements are present the increment the rear
       q.arr[q.tail]=data;  //add elements to next posistion
   }
 }
}
/* removing element from queue*/
void dequeue()
{
 int data;
 if(q.head==-1)    //checking if queue is empty
 {
     printf("\n\n\t queue is empty..");
     
 }
 else
 {
     data=q.arr[q.head];   //if queue is not empty taking the first inserted element
     printf("\n\n\t Element deleted from queue is =%d\n",data);
     if(q.head==q.tail)    //
     {
         q.head=-1;
         q.tail=-1;
     }
     else
     {
         q.head++; //if elemnt is removed changing the posistion of front 
     }
     
 }
}
/*displaying element in queue*/
void display()
{
    int i;
    if(q.head == -1)   //checking if queue is empty
    {
        printf("\n\n\t the queue is empty");
    }

    else    
    {
        printf("\n\n\t The queue elements are: "); //if queue is not empty the display the elements
        for(i=q.head;i<=q.tail;i++)
        {
            printf("\n %d\n",q.arr[i]);
        }
    }
    
}

