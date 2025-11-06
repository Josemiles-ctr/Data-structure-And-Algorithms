// A program to evaluate a postfix expression using stack implemented with arrays
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  // for isdigit()
#include <string.h> // for strlen()

#define MAX 100

int stack[MAX];
int top = -1;

// Function to push an element onto the stack
void push(int value) {
    if (top == MAX - 1)
        printf("Stack Overflow\n");
    else
        stack[++top] = value;
}

// Function to pop an element from the stack
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    } else
        return stack[top--];
}

// Function to evaluate a postfix expression
int evaluatePostfix(char exp[]) {
    int i;
    for (i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        // If the character is a digit, push it
        if (isdigit(ch)) {
            push(ch - '0'); // convert char to int
        }
        // If the character is an operator, pop two elements
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int val2 = pop();
            int val1 = pop();
            int result;

            switch (ch) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
            }

            push(result);
        }
    }
    return pop();  // final result
}

int main() {
    char exp[MAX];

    printf("Enter a postfix expression (e.g. 34+5*): ");
    scanf("%s", exp);

    int result = evaluatePostfix(exp);
    printf("Result of postfix expression = %d\n", result);

    return 0;
}
