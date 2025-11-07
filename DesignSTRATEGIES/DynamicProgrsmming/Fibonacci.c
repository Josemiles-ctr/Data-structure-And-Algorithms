#include <stdio.h>

// Fibonacci - Dynamic Programming (Memoization with Recursion)
int fibonacci(int n, int memo[]) {
    if (n <= 1) return n;
    
    // If already computed, return stored value
    if (memo[n] != -1) return memo[n];
    
    // Compute and store result
    memo[n] = fibonacci(n - 1, memo) + fibonacci(n - 2, memo);
    return memo[n];
}

int main() {
    int n = 10;
    
    // Initialize memoization array with -1
    int memo[n + 1];
    for (int i = 0; i <= n; i++) {
        memo[i] = -1;
    }
    
    printf("Fibonacci(%d) = %d\n", n, fibonacci(n, memo));
    
    printf("\nFibonacci sequence (0-%d): ", n);
    for (int i = 0; i <= n; i++) {
        // Reset memo for each call
        for (int j = 0; j <= n; j++) memo[j] = -1;
        printf("%d ", fibonacci(i, memo));
    }
    printf("\n");
    
    return 0;
}
