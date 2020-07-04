//C program to find if number is odd or even an then find square of number

#include <stdio.h>
main()
{
    int a;
    printf("enter value of a: ");   //inputing the number and  storing value to a
    scanf("%d",&a);
    if(a>1000)  //giving condition that number should be below 1000
    {
        printf("invalid no !");
        exit(0);
    }
    else if(a%2==0) //checking reminder to find if number is odd/even
    {
        printf("no is even & square of no is %d",a*a);

    }
    else{
        printf("no is odd and square is %d",a*a);
    }

}
