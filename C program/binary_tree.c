//program to create a binary tree in c
#include <stdio.h>
#include <stdlib.h>

struct BstNode {        //structure
    int data;
    struct BstNode* left;
    struct BstNode* right;
};
typedef struct BstNode node;
node* GetNewNode(int data)  //function for creating root node
    {
        node* newNode = (node*)malloc(sizeof(node));
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        return newNode;

}
node* Insert(node* rootPtr, int data)   //function for inserting new node
{
    if(rootPtr == NULL)
    {
    rootPtr = GetNewNode(data);
    }
    else if(data <= rootPtr->data)
    {
    rootPtr->left = Insert(rootPtr->left, data);
    }
    else
    {
    rootPtr->right = Insert(rootPtr->right, data);
    }
    return rootPtr;
}
int Search(struct BstNode* rootPtr, int data) //function for dearching if elemnt is present in node or not
{
    if(rootPtr == NULL) 
    {
    return 0;
    }
    else if(rootPtr->data == data)
    {
    return 1;   //return 1 if data found
    }
    else if(data <= rootPtr->data) //checking whether we want to search on left or right direction
    {
    return Search(rootPtr->left, data);
    }
    else {
    return Search(rootPtr->right, data);
    }
}
int main(void){
node* rootPtr;  //structure variable for accessing structure
rootPtr = NULL; //initially declaring root as null
rootPtr = Insert(rootPtr, 15);
rootPtr = Insert(rootPtr, 10);
rootPtr = Insert(rootPtr, 20);
rootPtr = Insert(rootPtr, 05);
rootPtr = Insert(rootPtr, 30);
rootPtr = Insert(rootPtr, 25);
int n;
printf("Enter number to be searched: \n");
scanf("%d",&n);
if(Search(rootPtr, n) == 1) {   //calling search  function
printf("Found\n");  
}
else {
printf("Not Found\n");
}
return 0;
}
