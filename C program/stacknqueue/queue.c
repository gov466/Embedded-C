 /*C Program to Implement a Queue using an Array*/

#include <stdio.h>
#include<stdlib.h>

#define MAX 50 //defining maximum size
 

void enqueue(); //function prototype

void dequeue();

void display();

int queue_array[MAX]; //array for queue

int tail = - 1;  //setting initial queue as empty

int head = - 1;

main()

{

    int choice;

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

            exit(1);

            default:

            printf("Wrong choice \n");

        } /* End of switch */

    } /* End of while */

} /* End of main() */

 
//fucntion for inserting element
void enqueue()

{

    int add_item;  //variable to storte element

    if (tail == MAX - 1) //checking if queue is full

    printf("Queue Overflow \n");

    else

    {

        if (head == - 1)  

        /*If queue is initially empty */

        head = 0;

        printf("Inset the element in queue : "); //inserting element

        scanf("%d", &add_item);

        tail = tail + 1;    //incrementing the posistion of tail 

        queue_array[tail] = add_item; //adding the next number 

    }

} /* End of insert() */

 
//deleting the element
void dequeue()

{

    if (head == - 1)// || head > tail) // checking if queue is empty

    {

        printf("Queue Underflow \n");

        return ;

    }

    else

    {

        printf("Element deleted from queue is : %d\n", queue_array[head]);

        head = head + 1; //deleting the element by increasing the head posistion 

    }

} /* End of delete() */

 
//function for display
void display()

{

    int i;

    if (head == - 1) //checking if queue is empty

        printf("Queue is empty \n");

    else

    {

        printf("Queue is : \n");  //displaying the queue elements

        for (i = head; i <= tail; i++)

            printf("%d ", queue_array[i]);

        printf("\n");

    }

} 
//
