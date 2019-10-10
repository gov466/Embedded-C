#include <stdio.h>

#define L  1024
#define TRUE 1U
#define FALSE 0U
//global
size_t s_top=0;
int s[L];
typedef unsigned short int bool_t;
bool_t stack_empty(void) 
{

   if(s_top==0)
      return TRUE;
   else
      return FALSE;
}

int pop() {
   int x;
	
   if(!stack_empty())
   {
      x = s[s_top];
      s_top = s_top - 1;   
      return x;
   } else {
      printf("Could not retrieve data, Stack is empty.\n");
   }
}

int push(int x) 
{

      s_top = s_top + 1;   
      s[s_top] = x;
    
}
int main() {
   // push items on to the stack 
 int loadarr[10]={52,-29,36,65,72,10,55,0,43,59}; 
 
    size_t i;
    for(i=0;i!=10;i++)
    {
        push(loadarr[i]);
        printf("pushing %d\n",loadarr[i]); 
    }
  

   // print stack data 
   int x;
   while(stack_empty()==FALSE) 
   {
      x = pop();
      printf("pop %d\n",x);
   }
   
   return 0;
}
