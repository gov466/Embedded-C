//c program to remove spaces from a string

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[]="p r o gramming"; //input string
    int i,count=0;
    printf("Before =%s",str); //displaying string before manipulation
    for(i=0;str[i]!='\0';i++) //loop starts
    {
        if(str[i]!=' ')     //checking condition for space
        {
            str[count]=str[i]; //if the position is not space then enter the value to str][count]
            count++;

            }
            }
 str[count]='\0';
    printf("\n after =%s",str);//printing the final string without spaces
    return 0;
}
