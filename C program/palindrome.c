// c program to find if number is plindrome or not 

#include<stdio.h>
void main()
{
    int n,rev=0,t;
    printf("enter the number to check palndrome");  //entering the number and storing value to variable n
    scanf("%d",&n);
    t=n;        //initializing value to n to t
    while(t!=0) //while loop with condition that t!=0
    {
        rev= rev*10;    //checking for palindrome
        rev=rev + t%10;
        t=t/10;
    }
    if(n==rev)  //checking of both reverse and n are equal
    {
        printf("number is palndrome /n",t); //if true the number is palindrome
    }
    else
    {
        printf("not palndrome \n"); //if false the statement prints not palindrome
    }
}
