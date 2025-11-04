// A program to demonstrate traversal in a singly linked list
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node*next;
};
int main(){
    //creating nodes manually
    struct Node n1, n2, n3;
    n1.data =10; n1.next= &n2;
    n2.data =20; n2.next= &n3;
    n3.data =30; n3.next= NULL;
    //head points to n1 which is the first node
    struct Node* head = &n1;
    //traverse the list and print
    struct Node* temp = head;
    while (temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("Null\n");
    return 0;

}