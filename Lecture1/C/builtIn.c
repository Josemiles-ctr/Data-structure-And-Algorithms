#include <stdio.h>
#include <stdbool.h>
int main() {
    
  /*Numeric types*/
    int x;
    double y;
    float z;

    /*Character types*/
    char k;
  

    /*Boolean types*/
    bool b =1;

    /*Void Type*/
    void *p;

    /*Derived Types*/

    /*Arrays*/
    int students[10];
    char name[5];

    /*POinters*/
    int *ptr;

    /*Functions*/
    int add(int x, int y);

    /*Structs*/
    struct student
    {
        int age;
        char name[20];
    };

    /*Unions*/
    union lecture
    {
        int age;
        char courseUnit[30];
    };

    /*Enums*/
    enum week{Mon, Tue, Web, Thur, Fri, Sat, Sun};



    /*Modifiers*/
    short x1;
    long x2;
    long long x3;
    long double f;
    signed int s1;
    signed char g1;
    unsigned int s2;
    unsigned char g2;

    return 0;
}