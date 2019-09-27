// C program for implementation of Bubble sort
#include <stdio.h>
#include <stdlib.h>
void sort(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// A function to implement bubble sort
void bubble_sort(int a[], int n, int dir)
{
    if(dir==0)
    {
    int i,j;

        for(i=0;i<n-1;i++)
        {
       // Last i elements are already in place
            for(j=0;j<n-i-1;j++)
            {
                if(a[j]>a[j+1])
                {
                sort(&a[j],&a[j+1]);
                }
            }
        }
    }
    else if(dir==1)
    {
        int i,j;

        for(i=0;i<n-1;i++)
        {
            for(j=0;j<n-i-1;j++)
            {
                if(a[j]<a[j+1])
                {
                sort(&a[j],&a[j+1]);
                }
            }
        }

    }
}
// Driver program to test above functions

int main()
{
    int a[ ]={5,3,4,6,1,2},n,i,dir;
    n=sizeof(a)/sizeof(a[0]); //finding size of array
    printf("the array elements are:\n");    //printing unsorted array
    for(i=0;i<n;i++)
    {
        printf("% d",a[i]);
    }
    printf("\nEnter 0 for ascending order and 1 for descending order:");    //statement to choose the order
    scanf("%d",&dir);
    bubble_sort(a,n,dir);   //calling the function for sorting
    printf("\nsorted array is\n");  // printing the sorted array
    for(i=0;i<n;i++)
        {
           printf("%d",a[i]);
        }

    return 0;
}
