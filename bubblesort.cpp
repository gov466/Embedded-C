// program for bubble sort without using function
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    cout<<"enter the limit";
    cin>>n;
    int a[n],i,j,temp;
 cout<<"enter the array";
 for(i=0;i<n;i++)
 {
 cin>>a[i];
 }
 for(i=0;i<n-1;i++)
 {
     for(j=0;j<n-i-1;j++)
     {
     if(a[j]>a[j+1])
     {
         temp=a[j];
         a[j]=a[j+1];
         a[j+1]=temp;

     }
     }
 }
 cout<<"array after sorting";
 for(i=0;i<n;i++)
 {
 cout<<a[i];
 }

}
