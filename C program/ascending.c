/* Example program to sort array in ascending order */
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int a[5],i,temp,j;
    cout<<"enter elements";
    for(i=0;i<5;i++)
    {
        cin>>a[i];
    }
     for(i=0;i<5;i++)
     {
         for(j=i+1;j<5;j++)
         {
             
             if(a[j]<a[i]) //comparing first and second values in array
              {
             temp=a[i];
             a[i]=a[j];
             a[j]=temp;
              }
         }
     }
    cout<<"new array";
    for(i=0;i<5;i++)
    {
        cout<<a[i];
    }
    
}
