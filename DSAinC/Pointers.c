#include <stdio.h>

//Attempt to use pointers

int main(){

    int age = 20;
    int *pAge = &age;

    printf("The value of age: %d",age);
    printf("The address of age: %p", &age);

    printf("The address stored at pAge: %p",pAge);
    printf("The value stored at: %d", *pAge);  //Defrencing the pointer

    return 0;
}