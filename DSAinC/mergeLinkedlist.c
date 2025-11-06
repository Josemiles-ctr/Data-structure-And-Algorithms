#include <stdio.h>
#include <stdlib.h>

//Attempt to merge two unsorted linked lists

//We shall first creaete the lists
struct Node{
    int data;
    struct Node *next;
};

struct Node* createNode(int data){
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

int main(){
    //First list
    struct Node *head1 = malloc(sizeof(struct Node));   //The header

    //The nodes
    struct Node *a = createNode(5);
    struct Node *b = createNode(9);
    struct Node *c = createNode(8);

    //Link the nodes
    head1->next = a;
    a->next = b;
    b->next = c;
    c->next = NULL;


    //Second list
    struct Node *head2 = malloc(sizeof(struct Node));   //The header

    //The nodes
    struct Node *d = createNode(11);
    struct Node *e = createNode(13);
    struct Node *f = createNode(14);

    //Link the nodes
    head2->next = d;
    d->next = e;
    e->next = f;
    f->next = NULL;

//Attempt to merge the lists
//We shall have to traverse the first list to the last value  hence need a target

struct Node *target = head1;
    while(target->next != NULL){
        target = target->next;
    }
    
    target->next = head2->next;  //We make our last node point to where head2 was pointing
    head2->next = NULL;

    //We print the combined list
    struct Node *current = head1->next;
    while (current != NULL)
    {
        printf("%d -> ",current->data);
        current = current->next;
    }
    

    



    return 0;
}