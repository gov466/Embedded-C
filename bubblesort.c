//Program to find the largest number in array
#include <stdio.h>
#include <stdlib.h>

int largest(int a[] ,int n )
{
    int i,large;
   large=a[0];
   for(i=1;i<n;i++)
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
    int a[5]={5,9,8,7,2},n;
    n=sizeof(a)/sizeof(a[0]);

    printf("the largest number in array is:%d",largest(a,n));

    return 0;
}
