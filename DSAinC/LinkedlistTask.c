#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// Attempt of the Linkedlist Topical Task

struct Node{
    int data;
    struct Node *next;
};

struct Node* createNewNode(int data){
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

//Method for the multiplication
struct Node* multiplyLinkedlist(struct Node *head1, int k){

    int num = toNumber(head1->next);
    int product = num * k;

    //We convert our product into a linked list again. We shall use an array with modulo division 
    int digits[4]; //make sure its big enough
    int index = 0;

    while (product > 0)
    {
        digits[index] = product % 10;   // Get the last digit
        product /= 10; //To actually remove that last digit, remember its an int not a double
        index ++;
    }

    //We attempt to create our linkedlist using the array

    int n = sizeof(digits) / sizeof(digits[0]);  // The number of elements in the array

    struct Node *head2 = malloc(sizeof(struct Node));

    struct Node *current = head2;

    // We create the linked list with this array
    for (int i = 0; i < n; i++)
    {
        current->next = createNewNode(digits[i]);
        current = current->next;
    }
    
    return head2;
}

//attempt to convert the values in the linkedlist to a number for numeric
int toNumber(struct Node *head){
    int number = 0;
    int place = 0;  //Will keep track of the powers of 10
    struct Node *target = head;    //Target for iteration

    while(target != NULL){
        number += target->data * pow(10, place);
        place ++;
        target = target->next;
    }

    return number;

   }

int main(){
    //Create the linked list to represent 273 with the least significant at the head
    //head1 is for the original linked list

    struct Node *head1 = malloc(sizeof(struct Node));

    //We create the nodes
    struct Node *first = createNewNode(2);
    struct Node *second = createNewNode(7);
    struct Node *third = createNewNode(3);

    //link them  note the change brought about by the least significant rule
    head1->next = third;
    third->next = second;
    second->next = first;
    first->next = NULL;

    struct Node *current = head1->next; //We start with the head
    while(current != NULL){
        printf("%d -> ", current->data);
        current = current->next;
        
    }

    printf("\n");

    struct Node *result =  multiplyLinkedlist(head1, 4);

    current = result->next; //We start with the head
    while(current != NULL){
        printf("%d -> ", current->data);
        current = current->next;
        
    }



    return 0;
}
