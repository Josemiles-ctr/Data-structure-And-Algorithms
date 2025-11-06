// A program to implement a queue using linked lists with basic operations
#include <stdio.h>
#include <stdlib.h>

// Structure for a queue node
struct Node {
    int data;
    struct Node* next;
};

// Front and rear pointers
struct Node* front = NULL;
struct Node* rear = NULL;

// Function to check if the queue is empty
int isEmpty() {
    return (front == NULL);
}

// Function to add (enqueue) an element to the queue
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed! Queue is FULL.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d enqueued to the queue.\n", value);
}

// Function to remove (dequeue) an element from the queue
void dequeue() {
    if (isEmpty()) {
        printf("Queue is EMPTY! Cannot dequeue.\n");
        return;
    }

    struct Node* temp = front;
    printf("%d dequeued from the queue.\n", front->data);
    front = front->next;

    // If queue becomes empty after dequeue
    if (front == NULL)
        rear = NULL;

    free(temp);
}

// Function to display the queue elements
void display() {
    if (isEmpty()) {
        printf("Queue is EMPTY!\n");
        return;
    }

    struct Node* temp = front;
    printf("Queue elements are: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to show current status of the queue
void status() {
    if (isEmpty()) {
        printf("Queue Status: EMPTY\n");
    } else {
        printf("Queue Status: Not Empty (dynamic size)\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Queue (Linked List) Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Status\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            status();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
