// A program to implement a queue using arrays with basic operations
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5   // Maximum size of the queue

int queue[SIZE];
int front = -1, rear = -1;

// Function to check if the queue is full
int isFull() {
    return rear == SIZE - 1;
}

// Function to check if the queue is empty
int isEmpty() {
    return front == -1 || front > rear;
}

// Function to add (enqueue) an element to the queue
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is FULL! Cannot enqueue %d.\n", value);
    } else {
        if (front == -1) front = 0;  // First element
        rear++;
        queue[rear] = value;
        printf("%d enqueued to the queue.\n", value);
    }
}

// Function to remove (dequeue) an element from the queue
void dequeue() {
    if (isEmpty()) {
        printf("Queue is EMPTY! Cannot dequeue.\n");
    } else {
        printf("%d dequeued from the queue.\n", queue[front]);
        front++;
    }
}

// Function to display the elements in the queue
void display() {
    if (isEmpty()) {
        printf("Queue is EMPTY!\n");
    } else {
        printf("Queue elements are: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

// Function to show current status of the queue
void status() {
    if (isEmpty()) {
        printf("Queue Status: EMPTY\n");
    } else if (isFull()) {
        printf("Queue Status: FULL\n");
    } else {
        printf("Queue Status: Not Full, Not Empty\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Queue Menu ---\n");
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
