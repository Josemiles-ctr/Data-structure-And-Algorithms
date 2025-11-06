// A program to evaluate a prefix expression using stacks implemented with arrays
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push a value onto the stack
void push(int value) {
    stack[++top] = value;
}

// Pop a value from the stack
int pop() {
    if (top == -1) {
        printf("Stack Underflow!\n");
        exit(1);
    }
    return stack[top--];
}

// Apply an operator to two operands
int applyOp(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

// Evaluate a prefix expression
int evaluatePrefix(char* exp) {
    int length = strlen(exp);

    // Scan from right to left
    for (int i = length - 1; i >= 0; i--) {
        char ch = exp[i];

        if (ch == ' ')
            continue;  // ignore spaces

        // If character is a digit, push it
        if (isdigit(ch)) {
            push(ch - '0');  // convert char to int
        }
        // If character is an operator
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int val1 = pop();
            int val2 = pop();
            int result = applyOp(val1, val2, ch);
            push(result);
        }
    }

    return pop();  // Final result
}

int main() {
    char exp[MAX];

    printf("Enter a prefix expression: ");
    scanf("%s", exp);

    int result = evaluatePrefix(exp);
    printf("Result = %d\n", result);

    return 0;
}
