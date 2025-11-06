#include <stdio.h>
#include <stdlib.h>

//Attempt to delete a node at the start of the list

struct Node{
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
    // We shall first create the linked list
    //We first create the head
    struct Node *head = malloc(sizeof(struct Node));

    //Then create the nodes
    struct Node *first = createNode(13);
    struct Node *second = createNode(24);
    struct Node *third = createNode(11);
    struct Node *fourth = createNode(17);
    struct Node *fifth = createNode(31);
    struct Node *sixth = createNode(37);
    struct Node *seventh = createNode(41);

    //We link the nodes
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = NULL;

    
    //Print before deletion
    struct Node *current = head->next; //We start with the head
    while(current != NULL){
        printf("%d -> ", current->data);
        current = current->next;
        
    }
    printf("\n");

    //Now we delete the first node
    //We first check if head is null meaning the list is empty

    if(head->next == NULL){
        printf("The list is empty");
    }
    else{
        //We use a variable to hold our header for security
        struct Node *temp = head->next;
        head->next = head->next->next;   //We now have the head pointing to the second node
        free(temp);  //We then delete the first node from memory
        
    }

    //Print after deletion
    current = head->next;
    while(current != NULL){
        printf("%d -> ", current->data);
        current = current->next;
        
    }

    printf("\n");


    //Attempt to delete a node at the end of a list
    //We check if the list is empty

    if(head->next == NULL){
        printf("The list is empty. No deletion");
    }
    
    //We have to tarverse to the last item but keep track of the second last(soon tobe last)
    struct Node *target = head;  //target for traversal
    struct Node *previous = NULL;  //Track the previous
    while (target->next != NULL)
    {
        previous = target;     //The previous node
        target = target->next;
    }

    //We now have previous as the second last node
    previous->next = NULL;   //We set its next to null
    free(target);             //We free up memory of the former last

        current = head->next;
    while(current != NULL){
        printf("%d -> ", current->data);
        current = current->next;
        
    }

    printf("\n");
    
    //Attempt to delete the node based on a key
    int key = 11;   //The data value of the node we intend to delete
    struct Node *tag = head;  //The target for traversal
    struct Node *prev = NULL;  //We need to keep track of the previous node

    while(tag->next != NULL){
        if (tag->data != key)
        {
            prev = tag;   //Track that node
            tag = tag->next;  //Move to the next node
        }
        else{                       //This is for the case where the target node is acquired
            prev->next = tag->next;  //We bypass the target node
            tag->next = NULL;
        }
        
    }

        current = head->next;
    while(current != NULL){
        printf("%d -> ", current->data);
        current = current->next;
        
    }

    return 0;
}

