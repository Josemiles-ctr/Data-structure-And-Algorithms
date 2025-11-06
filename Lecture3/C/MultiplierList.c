// A program to multiply a number represented as a singly linked list by an integer k
#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list node
struct ListNode {
    int val;
    struct ListNode* next;
};

// Function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to multiply linked list number by k
struct ListNode* multiplyLinkedList(struct ListNode* head, int k) {
    if (head == NULL || k == 0) {
        // Result is zero
        return createNode(0);
    }

    struct ListNode* result = NULL;
    struct ListNode* tail = NULL;
    struct ListNode* temp = head;

    int carry = 0;

    while (temp != NULL) {
        int product = temp->val * k + carry;
        int digit = product % 10;
        carry = product / 10;

        struct ListNode* newNode = createNode(digit);

        if (result == NULL) {
            result = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        temp = temp->next;
    }

    // Handle remaining carry
    while (carry > 0) {
        struct ListNode* newNode = createNode(carry % 10);
        carry /= 10;
        tail->next = newNode;
        tail = newNode;
    }

    return result;
}

// Function to print linked list
void printList(struct ListNode* head) {
    struct ListNode* temp = head;
    while (temp != NULL) {
        printf("[%d] -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Helper to insert at end (for test setup)
void insertEnd(struct ListNode** head, int val) {
    struct ListNode* newNode = createNode(val);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct ListNode* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Main function to test
int main() {
    struct ListNode* head = NULL;
    insertEnd(&head, 9);
    insertEnd(&head, 9);  // represents number 99

    int k = 5;

    printf("Original number: ");
    printList(head);

    struct ListNode* result = multiplyLinkedList(head, k);

    printf("After multiplying by %d: ", k);
    printList(result);

    return 0;
}
