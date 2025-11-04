//A program to demonstrate deletion in a singly linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void deleteFront(struct Node** head) {
    if (*head == NULL) return;
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteEnd(struct Node** head) {
    if (*head == NULL) return;
    struct Node* temp = *head, *prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL) *head = NULL;
    else prev->next = NULL;
    free(temp);
}

void deleteAtPosition(struct Node** head, int pos) {
    if (*head == NULL) return;
    struct Node* temp = *head;

    if (pos == 1) {
        *head = temp->next;
        free(temp);
        return;
    }

    struct Node* prev = NULL;
    for (int i = 1; temp != NULL && i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}

int main() {
    // Create sample list: 10 -> 20 -> 30 -> 40 -> NULL
    struct Node* head = malloc(sizeof(struct Node));
    head->data = 10;
    head->next = malloc(sizeof(struct Node));
    head->next->data = 20;
    head->next->next = malloc(sizeof(struct Node));
    head->next->next->data = 30;
    head->next->next->next = malloc(sizeof(struct Node));
    head->next->next->next->data = 40;
    head->next->next->next->next = NULL;

    printf("Original list:\n");
    display(head);

    printf("\nDeleting from front:\n");
    deleteFront(&head);
    display(head);

    printf("\nDeleting from end:\n");
    deleteEnd(&head);
    display(head);

    printf("\nDeleting from position 2:\n");
    deleteAtPosition(&head, 2);
    display(head);

    return 0;
}
