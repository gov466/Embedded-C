#include <stdio.h>
#include<stdlib.h>

 

#define MAX 50
 

void insert();

void delete();

void display();

int queue_array[MAX];

int tail = - 1;

int head = - 1;

main()

{

    int choice;

    while (1)

    {

        printf("1.Insert element to queue \n");

        printf("2.Delete element from queue \n");

        printf("3.Display all elements of queue \n");

        printf("4.Quit \n");

        printf("Enter your choice : ");

        scanf("%d", &choice);

        switch (choice)

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

 

void insert()

{

    int add_item;

    if (tail == MAX - 1)

    printf("Queue Overflow \n");

    else

    {

        if (head == - 1)

        /*If queue is initially empty */

        head = 0;

        printf("Inset the element in queue : ");

        scanf("%d", &add_item);

        tail = tail + 1;

        queue_array[tail] = add_item;

    }

} /* End of insert() */

 

void delete()

{

    if (head == - 1 || head > tail)

    {

        printf("Queue Underflow \n");

        return ;

    }

    else

    {

        printf("Element deleted from queue is : %d\n", queue_array[head]);

        head = head + 1;

    }

} /* End of delete() */

 

void display()

{

    int i;

    if (head == - 1)

        printf("Queue is empty \n");

    else

    {

        printf("Queue is : \n");

        for (i = head; i <= tail; i++)

            printf("%d ", queue_array[i]);

        printf("\n");

    }

} 
//
