#include <stdio.h>
#include <stdbool.h>
int main() {
    /*Numeric types*/
    int x;
    double y;
    float z;

    /*Charater types*/
    char k;

    /*Boolean types*/
    bool b =1;
    printf("%d\n", b);
    /*Voids*/
    void *p;

    /*Derived Types*/
    int students[10];
    char name[5];
    int *ptr;
    int add(int x, int y);
    struct student
    {
        int age;
        char name[20];
    };
    union lecture
    {
        int age;
        char courseUnit[30];
    };
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