#include<iostream>
#include<cmath>
using namespace std;
float fun(float a)
{                             //function for main equation
 float b;
 b=a*a*a*a*a+a*a*a+3;   
 return(b);
}
using namespace std;
int main()    //main function starts
{
 float x1,x2,x3,f1,f2,e,c=0.001;
 cout<< "enter the values of x1 and x2";
 cin>>x1;
 cin>>x2;
 cout<<"x1\t      x2\t       x3\t        f1\t        f2\t";
 do
 {
  f1=fun(x1);     //finding value of x1 in function
  f2=fun(x2);     /finding value of x2 in function
  x3=((x1*f2)-(x2*f1))/(f2-f1); //main secant equation
  x1=x2;
  x2=x3;
  cout<<"\n"<<x1<<"\t"<<x2<<"\t"<<x3<<"\t\t"<<f1<<"\t"<<f2; //displaying the values
 }
 while(e>c);
  
}
