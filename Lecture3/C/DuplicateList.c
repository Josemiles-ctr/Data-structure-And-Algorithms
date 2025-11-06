// A program to duplicate a singly linked list
#include <stdio.h>
#include <stdlib.h>

// Define a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to display a linked list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to copy a linked list
struct Node* copyList(struct Node* head) {
    if (head == NULL)
        return NULL;

    // Create the head node of the new list
    struct Node* newHead = createNode(head->data);
    struct Node* tempOriginal = head->next;
    struct Node* tempCopy = newHead;

    // Traverse the original list and copy nodes
    while (tempOriginal != NULL) {
        tempCopy->next = createNode(tempOriginal->data);
        tempCopy = tempCopy->next;
        tempOriginal = tempOriginal->next;
    }

    return newHead;
}

int main() {
    // Create an example linked list: 10 -> 20 -> 30 -> NULL
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);

    printf("Original List:\n");
    display(head);

    // Copy the list
    struct Node* duplicate = copyList(head);

    printf("\nCopied (Duplicate) List:\n");
    display(duplicate);

    return 0;
}
