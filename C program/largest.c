/*Program to find the largest number in array*/
#include <stdio.h>
#include <stdlib.h>

int largest(int a[] ,int n ) // C function to find maximum in arr[] of size n
{
    int i,large;
   large=a[0]; // Initialize maximum element
   for(i=1;i<n-1;i++)
    // Traverse array elements from second and
    // compare every element with current max
   {
       if(a[i]>large)
       {
           large=a[i];

       }
   }
   return large;

}
int main()
{
    int a[100],n,l,i;
    printf("enter the limit");      //Enter the limit
    scanf("%d",&n);
    printf("Enter the elements");       //Enter user defined numbers
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    l=largest(a,n);             //Calling the function
    printf("the largest number in array is:",l);    //printing largest number

    return 0;
}
