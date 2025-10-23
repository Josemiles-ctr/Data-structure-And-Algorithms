# include <stdio.h>
#include <stdbool.h>
int main() {
    /*Implementing a boolean of true and false in C*/
    /* Using _Bool data type manually */
    _Bool isTrue = 1;
    if (isTrue) {
        printf("True");
    } else {
        printf("False\n");
    }

    /* Using stdbool.h library */
    bool isFalse = false;
    bool isTrue = !isFalse;
    return 0;
}   