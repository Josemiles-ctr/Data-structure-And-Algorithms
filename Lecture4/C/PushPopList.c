//A program to demonstrate push and pop operations in a stack using linked list
#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;  // top of the stack

// Function to push an element onto the stack
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Stack Overflow! Memory not available.\n");
        return;
    }

    newNode->data = value;
    newNode->next = top;  // point to previous top
    top = newNode;        // update top pointer

    printf("%d pushed to stack.\n", value);
}

// Function to pop an element from the stack
void pop() {
    if (top == NULL) {
        printf("Stack Underflow! Cannot pop.\n");
        return;
    }

    struct Node* temp = top;
    printf("%d popped from stack.\n", top->data);
    top = top->next;  // move top to next node
    free(temp);       // free the removed node
}

// Function to display the stack
void display() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    struct Node* temp = top;
    printf("Stack elements are:\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

// Main function to test the stack operations
int main() {
    int choice, value;

    while (1) {
        printf("\n--- Stack Menu (Linked List) ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
