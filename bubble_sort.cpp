// program for bubble sort with using function
#include <iostream>
#include <string>
using namespace std;
void bubble_sort(int *a,int n)
{
    int i,j,temp;
 for(i=0;i<n-1;i++)
 {
     for(j=0;j<n-i-1;j++)
     {
     if(a[j]>a[j+1])
     {
        swap(a[i],a[i+1]);
        /* temp=a[j];
         a[j]=a[j+1];
         a[j+1]=temp;*/

     }
     }
 }
 cout<<"array after sorting";
 for(i=0;i<n;i++)
 {
 cout<<a[i];
 }
}
int main()
{
    int n;
    cout<<"enter the limit";
    cin>>n;
    int a[n],i;
 cout<<"enter the array";
 for(i=0;i<n;i++)
 {
 cin>>a[i];
 }
 bubble_sort(a,n);
}


