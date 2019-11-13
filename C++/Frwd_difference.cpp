/*Write an application to calculate the value of f(x)=sin(x) at x=45 degrees 
based on the Maclaurin series. In order to calculate the derivatives of this function
use “Forward Difference” method with step size of 1 degree.   */

#include <iostream>
#include <cmath>
using namespace std;

int factorial(int n)
{
if(n==0)
{
return 1;
}
else
{
return n*factorial(n-1);
}
}

int main()

{
int n = 30;
double x = 0.785398;
double ans = 0;
int  i = 1;
bool positive = true;
while(i<n)
{
if(positive)
{
ans = ans + pow(x,i)/factorial(i);
positive = !positive;
}
else
{
ans = ans - pow(x,i)/factorial(i);
positive = !positive;
}
i+=2;
}

cout<<"Sin(45 Degree) =  "<<ans<<endl;

return 0;
}

