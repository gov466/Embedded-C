#include<iostream>
     
    using namespace std;
     
    //function used is x^3-2x^2+3
    double func(double x)
    {
        return x*x*x*x*x + x*x*x + 3;
    }
     
    double c;
     
    void bisection(double a,double b)
    {
        if(func(a) * func(b) >= 0)
        {
            cout<<"Incorrect a and b";
            return;
        }
     
        c=a;
     
        while ((b-a) >= 0.01) //tell about interval is sufficently small
        {
            c = (a+b)/2;
            if (func(c) == 0.0){
                
                break;
            }
            else if (func(c)*func(a) < 0){
                   
                    b=c;
            }
            else{
                    
                    a=c;
            }
        }
    }
     
    int main()
    {
        double a,b;
        a=-2;
        b=2;
        bisection(a,b); 
        cout<<"\n";
        cout<<"The value of root is = "<<c<<endl;
     
        return 0;
    }
