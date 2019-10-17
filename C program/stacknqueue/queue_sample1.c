// queue operation.c
#include <stdio.h>
#include<conio.h>
//sructure declaration
#define MAX 5       //defining size as 5
void enqueue();     //prototype
void dequeue();
void display();

int queue[MAX];
int front=-1,rear=-1;
void main()
{
    int ch;
    do{
        printf("\n1.insertion \n2.Deletion\n3.Disp[lay\n4.exit");
        printf("\nenter your choice]\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: enqueue();
            break;
            case 2: dequeue();
            break;
            case 3: display();
            break;
            //case 4: exit;
            //break;
            
        }
    }while(ch!=4);
}

void enqueue()
{
    int item,i;
    if(front==0&&rear==MAX-1)
    {
        printf("\nqueue overflow");
    }
    else
    {
        printf("\nenter element which you want to insert\n");
        scanf("%d",&item);
        if(front==-1) //whhen queue is empty
        {
            front=rear=0;
        }
        else if(rear=MAX-1)//when fromt!=0 and rear=MAX-1
        {
            for(i=front;i<=rear;i++)
            {
                queue[i-front]=queue[i];
                
            }
            rear=rear-front+1;
            front=0;
        }
        else
        {
            rear++;
            
        }
        queue[rear]=item;
    }
    
}
void dequeue()
{
    if(front=-1)
    {
        printf("\n queue underflow\n");
        
    }
    else
    {
        printf("\n%d deleted from queue \n",queue[front]);
        if(front==rear)
        {
            front=rear=-1;
        }
        else
        {
            front++;
        }
    }
}
void display()
{   
    int i;
    if(front==-1)
    {
        printf("\nqueue underflow\n");
    }
    else
    {
        printf("\nqueue elements---->\n");
        for(i=front;i<=rear;i++)
        {
           printf("%d",queue[i]); 
        }
    }
}
