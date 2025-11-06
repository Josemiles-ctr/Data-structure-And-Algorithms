// A program to convert infix expression to prefix expression using stack
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push onto stack
void push(char c) {
    stack[++top] = c;
}

// Pop from stack
char pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

// Return precedence
int precedence(char c) {
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

// Function to reverse a string
void reverse(char *exp) {
    int len = strlen(exp);
    for (int i = 0; i < len / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[len - i - 1];
        exp[len - i - 1] = temp;
    }
}

// Function to convert infix to postfix
void infixToPostfix(char *infix, char *postfix) {
    int i, k = 0;
    char c;
    top = -1;

    for (i = 0; infix[i] != '\0'; i++) {
        c = infix[i];

        if (c == ' ')
            continue;

        // If operand, add to output
        if (isalnum(c)) {
            postfix[k++] = c;
        }
        // If '(', push
        else if (c == '(') {
            push(c);
        }
        // If ')', pop until '('
        else if (c == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[k++] = pop();
            pop(); // remove '('
        }
        // If operator
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(c))
                postfix[k++] = pop();
            push(c);
        }
    }

    // Pop remaining operators
    while (top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';
}

// Main function to convert infix → prefix
void infixToPrefix(char *infix, char *prefix) {
    char temp[MAX];
    strcpy(temp, infix);

    // Step 1: Reverse infix expression
    reverse(temp);

    // Step 2: Replace '(' with ')' and vice versa
    for (int i = 0; temp[i] != '\0'; i++) {
        if (temp[i] == '(')
            temp[i] = ')';
        else if (temp[i] == ')')
            temp[i] = '(';
    }

    // Step 3: Get postfix of the modified expression
    char postfix[MAX];
    infixToPostfix(temp, postfix);

    // Step 4: Reverse postfix to get prefix
    reverse(postfix);
    strcpy(prefix, postfix);
}

int main() {
    char infix[MAX], prefix[MAX];

    printf("Enter an infix expression: ");
    scanf("%[^\n]", infix);

    infixToPrefix(infix, prefix);

    printf("Prefix Expression: %s\n", prefix);

    return 0;
}
