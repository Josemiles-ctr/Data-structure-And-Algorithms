#include <stdio.h>
#include <stdlib.h>

 struct Node{
int data;
struct Node*next;
    };
int main(){
struct Node n1, n2, n3, n4;
n1.data=5;n1.next=&n2;
n2.data=10;n2.next=&n3;
n3.data=15;n3.next=&n4;
n4.data=20;n4.next=NULL;
struct Node*head=&n1;
struct Node*temp=head;
while(temp !=0){
    printf("%d->", temp->data);
    temp=temp->next;
}

}
