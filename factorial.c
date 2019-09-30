//c program to  find the factorial of number

#include <stdio.h>
#include <stdlib.h>
 main()
{
   int a,i,f=1; //declaration of variables
   printf("Enter the number to find the factorial: "); //Entering the number
   scanf("%d",&a);              // storing the number to variable a

    for(i=1;i<=a;i++)
    {
        f=f*i;      //finding factorial
    }
    printf("factorial = %d",f);     //printing factorial
    return 0;
}
