#include <stdio.h>
#include <stdlib.h>

// Attempt to create a linked list of 3 nodes (We will use a struct)

struct Node {
    int data;                   //This will rep a node with 2 parts, the data and the link/pointer
    struct Node *next;
};

int main(){

    // We create the links
    struct Node *head = NULL;   //Leave them null for now
    struct Node *first = NULL;
    struct Node *second = NULL;
    struct Node *third = NULL;

    //We assign each of these to point to memory locations of nodes
    head = malloc(sizeof(struct Node));
    first = malloc(sizeof(struct Node));
    second = malloc(sizeof(struct Node));
    third = malloc(sizeof(struct Node));

    //Fill the data values, remember the head doesnt contain data
    first->data = 12;
    second->data = 25;
    third->data = 76;

    //We assign the memory addresses
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = NULL;


    //Now we try to traverse the list and count the numner of nodes

    struct Node *current = head->next; //We start with the head
    int count = 0; // we initialize the counter

    while(current != NULL){
        printf("%d -> ", current->data);
        current = current->next;
        count ++;
    }

    printf("There are %d nodes", count);
    
    

    

    

    return 0;
}
