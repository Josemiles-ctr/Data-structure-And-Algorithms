//A program to demonstrate insertion in a singly linked list
#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Insert at the beginning
void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;  // Point new node to current head
    *head_ref = new_node;        // Move head to new node
}

// Insert at the end
void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) { // If list is empty
        *head_ref = new_node;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

// Insert after a given position (middle)
void insertAtPosition(struct Node** head_ref, int position, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;

    if (position == 1) {  // Same as insert at beginning
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }

    struct Node* temp = *head_ref;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
        free(new_node);
        return;
    }

    new_node->next = temp->next;
    temp->next = new_node;
}

// Main function
int main() {
    struct Node* head = NULL;

    // Insert nodes
    insertAtEnd(&head, 10);   // 10
    insertAtEnd(&head, 20);   // 10 -> 20
    insertAtEnd(&head, 30);   // 10 -> 20 -> 30
    printList(head);

    insertAtBeginning(&head, 5);  // 5 -> 10 -> 20 -> 30
    printList(head);

    insertAtPosition(&head, 3, 15); // 5 -> 10 -> 15 -> 20 -> 30
    printList(head);

    insertAtEnd(&head, 40); // 5 -> 10 -> 15 -> 20 -> 30 -> 40
    printList(head);

    return 0;
}