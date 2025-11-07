#include <stdio.h>
#include <stdlib.h>

// Define node structure for doubly linked list
struct Node {
    int data;
    struct Node* next;  // Pointer to next node
    struct Node* prev;  // Pointer to previous node
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Function to insert at the end
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
    if (*head == NULL) {
        // Empty list - new node becomes head
        *head = newNode;
        return;
    }
    
    // Traverse to last node
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    // Link the new node to the end
    temp->next = newNode;
    newNode->prev = temp;  // Set previous pointer
}

// Function to insert at beginning
void insertBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
    newNode->next = *head;
    
    if (*head != NULL) {
        (*head)->prev = newNode;  // Update old head's previous pointer
    }
    
    *head = newNode;  // New node becomes head
}

// Function to display list forward
void displayForward(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    struct Node* temp = head;
    printf("Forward: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to display list backward
void displayBackward(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    
    // Traverse to last node
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    // Traverse backward using prev pointers
    printf("Backward: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

// Function to delete a node by value
void deleteNode(struct Node** head, int key) {
    if (*head == NULL) return;
    
    struct Node* temp = *head;
    
    // Find the node to delete
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    
    // Node not found
    if (temp == NULL) return;
    
    // Adjust pointers
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    } else {
        // Deleting head node
        *head = temp->next;
    }
    
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    
    free(temp);  // Free memory
}

int main() {
    struct Node* head = NULL;

    // Insert at end
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    
    // Insert at beginning
    insertBeginning(&head, 5);
    insertBeginning(&head, 1);
    
    // Display
    displayForward(head);
    displayBackward(head);
    
    // Delete a node
    printf("\nAfter deleting 20:\n");
    deleteNode(&head, 20);
    displayForward(head);
    displayBackward(head);
    
    return 0;
}