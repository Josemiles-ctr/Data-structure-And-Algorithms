#include <stdio.h>
#include <string.h>

//Attempt to implement a struct

struct Student
{
    char name[6];     //There is no string datatype, we use an array of characters
    int age;
};


int main(){

    struct Student s1;
    struct Student s2;

    strcpy(s1.name, "Aburek");
    s1.age = 20;

    strcpy(s2.name, "manuel");
    s2.age = 23; 
    s2.age = 23; 


    printf("%s",s1.name);
    printf("%d",s1.age);
    printf("%s",s2.name);
    printf("%d",s2.age);

    return 0;
}