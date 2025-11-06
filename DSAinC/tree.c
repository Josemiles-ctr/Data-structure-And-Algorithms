#include <stdio.h>
#include <stdlib.h>

//Attempt to implement a tree and traversal
//Structure of tree

struct Node{
    int data;            //Value stored
    struct Node *left;   //pointer to left child
    struct Node *right;  //pointer to right child
};

//Fuction to create a node

struct Node* createNewNode(int data){
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
};


//Inorder Traversal
    void inOrder(struct Node* treeNode){
        if(treeNode == NULL) return;  //exit out of recursion at a leaf

        inOrder(treeNode->left);
        printf("%d ,",treeNode->data);
        inOrder(treeNode->right);

    };

    //Preorder Traversal
    void preOrder(struct Node* treeNode){
        if(treeNode == NULL) return;  //exit out of recursion at a leaf

        printf("%d ,",treeNode->data);
        preOrder(treeNode->left);
        preOrder(treeNode->right);

    };

    //Postorder Traversal
    void postOrder(struct Node* treeNode){
        if(treeNode == NULL) return;  //exit out of recursion at a leaf

        postOrder(treeNode->left);
        postOrder(treeNode->right);
        printf("%d ,",treeNode->data);

    };

int main(){
    //Creating the root
    struct Node *root = createNewNode(1);

    //Create root's child nodes
    root->left = createNewNode(2);
    root->right = createNewNode(3);

    //Create left subtree
    root->left->left = createNewNode(4);
    root->left->right = createNewNode(5);

    //Inorder
    printf("Inorder Traversal: \n");
    inOrder(root);

    //Preorder
    printf("\nPreorder Traversal: \n");
    preOrder(root);

    //Postorder
    printf("\nPostorder Traversal: \n");
    postOrder(root);


}