#include <stdio.h>
#include <stdlib.h>

//Attempt to insert a node at the front of a linked list

struct Node
{
    int data;
    struct Node *next;
};

struct Node* createNode(int data){
    struct Node *newNode = malloc(sizeof(struct Node));    //This will be the method for creating
    newNode->data = data;                                  //So there is no code repetion
    newNode->next = NULL;

    return newNode;
}

int main(){

    //Create a header
    struct Node *head = malloc(sizeof(struct Node));

    //We create the nodes
    struct Node *second = createNode(12);
    struct Node *third = createNode(24);
    struct Node *fifth = createNode(35);

    //We link the nodes
    head->next = second;
    second->next = third;
    third->next = fifth;
    fifth->next = NULL;


    //Attempt to insert a node at the front
    struct Node *first = createNode(7);     //We create our node
    if(first == NULL){
        printf("Memory overflow, Insertion impossible");  //We check if node was created
    }
    else{
        first->next = head->next;   //We assing the first node to point to the former first node
        head->next = first;      //then the header will point to our node 
    }

    //Attempt to insert a node at the end
    //We shall have to traverse up to the last node(ie whose next is NULL)  we will need a target
    struct Node *last = createNode(53);
    struct Node *target = head;

    while(target->next != NULL){
        target = target->next;       // We switch the pointer untill we get our guy
    }

    target->next = last;             //make it point to the new node
    last->next = NULL;               //Terminate the new node


    //Attempt to insert a node in between
    //We will need to traverse to a node with a give key/data for us to insert after

    int key = 24;     //the data value for the third node
    struct Node *fourth = createNode(29);   //The new node
    struct Node *tag = head;   //Target for traversal

    while(tag->data != 24){
        tag = tag->next;
    }

    fourth->next = tag->next;    //the new node has to point to where the target was 
    tag->next = fourth;

    
    struct Node *current = head->next; //We start with the head
    while(current != NULL){
        printf("%d -> ", current->data);
        current = current->next;
        
    }

    


    return 0;
}