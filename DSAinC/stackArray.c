#include <stdio.h>
#define MAX 5  //Fixed size of the array

//Attempt to create a stack represented by an array

int stack[MAX]; //The stack
int top = 0;  //Top index of the stack

//Push operation
void push(int x){
    if(top == MAX){
        printf("Stack overflow!!!"); //Indicates stack is full
    }
    else{
        stack[top] = x;
        top++;
    }
}

int pop(){
    int item; //The value that has been popped
    if(top == 0){
        printf("The stack is empty");
    }
    else{
        item = stack[top - 1];
        top--;
    }

    return item;
}

int main(){
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
       
    printf("%d",pop());

    for (int i = 0; i < MAX; i++)
    {
        printf("%d,",stack[i]);
    }
    

    
}