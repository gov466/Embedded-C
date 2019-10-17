#include <stdio.h>
#include<stdlib.h>

#define MAX 50  //defining maximum size of queue
 

void insert(); //prototype

void delete();

void display();

int queue_array[MAX];  //array for queue

int tail = - 1;  //setting initail value of tail and queue to -1 saying that queue is empty

int head = - 1;

main()

{

    int choice;   

    while (1)    //infinite while loop

    {

        printf("1.Insert element to queue \n");

        printf("2.Delete element from queue \n");

        printf("3.Display all elements of queue \n");

        printf("4.Quit \n");

        printf("Enter your choice : ");  //entering choice by user

        scanf("%d", &choice);

        switch (choice)  //switch case statement for calling different functioins

        {

            case 1:

            insert();

            break;

            case 2:

            delete();

            break;

            case 3:

            display();

            break;

            case 4:

            exit(1);

            default:

            printf("Wrong choice \n");

        } /* End of switch */

    } /* End of while */

} /* End of main() */

 

void insert()  //funcion for inseerting an element to queue

{

    int add_item;

    if (tail == MAX - 1) //checking if the queue is full

    printf("Queue Overflow \n");

    else

    {

        if (head == - 1)   

        /*If queue is initially empty */

        head = 0; //setting position of head to zero

        printf("Inset the element in queue : ");

        scanf("%d", &add_item); //adding element to queue

        tail = tail + 1; //changing the posistion to tail

        queue_array[tail] = add_item;  //adding element to tail

    }

} /* End of insert() */

 

void delete()

{

    if (head == - 1 ) //checking if queue is empty

    {

        printf("Queue Underflow \n");

        return ;

    }

    else

    {

        printf("Element deleted from queue is : %d\n", queue_array[head]);

        head = head + 1; //deleting and changing the posistion of head to next element

    }

} /* End of delete() */

 /*displaying queue */

void display()

{

    int i;

    if (head == - 1) //checking if queue is empty 

        printf("Queue is empty \n");

    else

    {

        printf("Queue is : \n"); //displaying the queue elements

        for (i = head; i <= tail; i++)

            printf("%d ", queue_array[i]);

        printf("\n");

    }

} 
//
