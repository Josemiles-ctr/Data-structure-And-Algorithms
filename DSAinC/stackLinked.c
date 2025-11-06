#include <stdio.h>

//Attempt to create a stack represented by a linked list

struct Node{
    int data;
    struct Node *next;
};

struct Node *top = NULL;  //The top pointer

//We will use the push method to create the new node,

void push(int data){
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = top;

    top = newNode;   //Really internalize this, This is done so that each new
                     //Created is the top most(with the top pointer)

    printf("Pushed value: %d",newNode->data);
}

int pop(){
    if(top == NULL){
        printf("Stackover floww!!!");
        return -1;
    }
    else{
        struct Node *temp = top;
        int value = temp->data;
        top = top->next;

        free(temp);
        return value;
    }
}

void printStack() {
    struct Node* current = top;   // start from the top
    printf("Stack: ");
    if (current == NULL) {
        printf("empty\n");
        return;
    }
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;  // move down
    }
    printf("\n");
}

int main(){
    push(3);
    push(4);
    push(5);

    pop();

    printStack();
}