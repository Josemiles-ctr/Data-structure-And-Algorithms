// A program to evaluate an infix expression using stacks implemented with arrays
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  // for isdigit()
#include <math.h>

#define MAX 100

int values[MAX];
char ops[MAX];
int topValues = -1, topOps = -1;

// Push integer value to value stack
void pushValue(int val) {
    values[++topValues] = val;
}

// Pop integer value
int popValue() {
    return values[topValues--];
}

// Push operator to operator stack
void pushOp(char op) {
    ops[++topOps] = op;
}

// Pop operator
char popOp() {
    return ops[topOps--];
}

// Function to return precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
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

// Evaluate the infix expression
int evaluate(char* exp) {
    for (int i = 0; exp[i] != '\0'; i++) {
        // Skip spaces
        if (exp[i] == ' ')
            continue;

        // If current token is a number, push it to value stack
        else if (isdigit(exp[i])) {
            int val = 0;
            // There may be more than one digit
            while (isdigit(exp[i])) {
                val = (val * 10) + (exp[i] - '0');
                i++;
            }
            i--;
            pushValue(val);
        }

        // If current token is '(', push it to ops stack
        else if (exp[i] == '(') {
            pushOp(exp[i]);
        }

        // If current token is ')', solve the entire bracket
        else if (exp[i] == ')') {
            while (topOps != -1 && ops[topOps] != '(') {
                int val2 = popValue();
                int val1 = popValue();
                char op = popOp();
                pushValue(applyOp(val1, val2, op));
            }
            popOp(); // Remove '(' from ops stack
        }

        // Current token is an operator
        else {
            while (topOps != -1 && precedence(ops[topOps]) >= precedence(exp[i])) {
                int val2 = popValue();
                int val1 = popValue();
                char op = popOp();
                pushValue(applyOp(val1, val2, op));
            }
            pushOp(exp[i]);
        }
    }

    // Entire expression has been parsed, apply remaining ops
    while (topOps != -1) {
        int val2 = popValue();
        int val1 = popValue();
        char op = popOp();
        pushValue(applyOp(val1, val2, op));
    }

    return popValue(); // Top of value stack is the result
}

int main() {
    char exp[MAX];

    printf("Enter an infix expression:");
    scanf("%[^\n]", exp); // read entire line including parentheses

    int result = evaluate(exp);
    printf("Result = %d\n", result);

    return 0;
}
