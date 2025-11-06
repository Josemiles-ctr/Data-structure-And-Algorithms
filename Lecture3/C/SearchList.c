//A program to demonstrate searching for an element in a singly linked list
#include <stdio.h>
#include <stdlib.h>

// Define structure for a node
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

// Function to insert node at the end of a linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Function to search for an element in the linked list
int search(struct Node* head, int key) {
    struct Node* temp = head;
    int position = 1; // to track the node position

    while (temp != NULL) {
        if (temp->data == key) {
            return position; // found at this position
        }
        temp = temp->next;
        position++;
    }
    return -1; // not found
}

// Function to display the linked list
void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;

    // Insert some elements
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    insertEnd(&head, 40);
    insertEnd(&head, 50);

    printf("Linked List: ");
    display(head);

    int key;
    printf("Enter element to search: ");
    scanf("%d", &key);

    int position = search(head, key);

    if (position != -1)
        printf("Element %d found at position %d.\n", key, position);
    else
        printf("Element %d not found in the list.\n", key);

    return 0;
}
