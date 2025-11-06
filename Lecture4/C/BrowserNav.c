#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define MAX_URL_LENGTH 100

// Stack structure for strings
typedef struct {
    char data[MAX_STACK_SIZE][MAX_URL_LENGTH];
    int top;
} Stack;

// Initialize stack
void initStack(Stack *stack) {
    stack->top = -1;
}

// Check if stack is empty
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Check if stack is full
int isFull(Stack *stack) {
    return stack->top == MAX_STACK_SIZE - 1;
}

// Push element onto stack
void push(Stack *stack, const char *url) {
    if (isFull(stack)) {
        printf("Stack overflow!\n");
        return;
    }
    stack->top++;
    strcpy(stack->data[stack->top], url);
}

// Pop element from stack
void pop(Stack *stack, char *url) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        return;
    }
    strcpy(url, stack->data[stack->top]);
    stack->top--;
}

// Peek at top element
char* peek(Stack *stack) {
    if (isEmpty(stack)) {
        return NULL;
    }
    return stack->data[stack->top];
}

// Get stack size
int size(Stack *stack) {
    return stack->top + 1;
}

// Clear stack
void clear(Stack *stack) {
    stack->top = -1;
}

int main() {
    char *google = "https://www.google.com";
    char *mak = "https://www.mak.ac.ug";
    char *facebook = "https://www.facebook.com";
    char *twitter = "https://www.twitter.com";
    char *instagram = "https://www.instagram.com";
    char *linkedin = "https://www.linkedin.com";
    
    char *urls[] = {google, mak, facebook, twitter, instagram, linkedin};
    int numUrls = 6;
    
    Stack history;
    Stack forwardStack;
    initStack(&history);
    initStack(&forwardStack);
    
    int urlIndex = 0;
    
    // Start with the first URL
    push(&history, urls[urlIndex]);
    printf("Current page: %s\n", peek(&history));
    
    while (1) {
        printf("\nEnter your choice:\n");
        printf("1 - Visit next URL\n");
        printf("2 - Go back\n");
        printf("3 - Go forward\n");
        printf("4 - View current page\n");
        printf("0 - Exit\n");
        printf("Choice: ");
        
        int response;
        scanf("%d", &response);
        
        switch (response) {
            case 1: {
                // Visit next URL
                urlIndex++;
                if (urlIndex >= numUrls) {
                    urlIndex = 0;
                }
                push(&history, urls[urlIndex]);
                clear(&forwardStack); // Clear forward history when visiting new page
                printf("Visiting: %s\n", urls[urlIndex]);
                break;
            }
            case 2: {
                // Go back
                if (size(&history) > 1) {
                    char temp[MAX_URL_LENGTH];
                    pop(&history, temp);
                    push(&forwardStack, temp);
                    printf("Going back to: %s\n", peek(&history));
                } else {
                    printf("No previous page in history!\n");
                }
                break;
            }
            case 3: {
                // Go forward
                if (!isEmpty(&forwardStack)) {
                    char temp[MAX_URL_LENGTH];
                    pop(&forwardStack, temp);
                    push(&history, temp);
                    printf("Going forward to: %s\n", peek(&history));
                } else {
                    printf("No forward page available!\n");
                }
                break;
            }
            case 4: {
                // View current page
                if (!isEmpty(&history)) {
                    printf("Current page: %s\n", peek(&history));
                } else {
                    printf("No page loaded!\n");
                }
                break;
            }
            case 0: {
                printf("Exiting...\n");
                return 0;
            }
            default:
                printf("Invalid choice!\n");
        }
    }
    
    return 0;
}
