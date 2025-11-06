//Attemt to compute Fibonacci numbers using recursion
#include <stdio.h>
#include <stdlib.h>

//Function to compute Fibonacci number at position n
int fibonacci(int n){
    int result = 0;  //Will hold the Fibonacci number
    
    if (n == 0 || n == 1){
        result = n;
    } else {
        result = fibonacci(n - 1) + fibonacci(n - 2);
    }
    return result;
}

//Now we want to fix this function to use memoization for efficiency (dynamic programming)
//we memo as an array to store previously computed Fibonacci numbers
int fibonacci_memo(int n, int memo[]){
    int result = 0;
    // check sentinel (-1 means "not computed")
    if (memo[n] != -1) {
        return memo[n];
    }
    if(n ==0 || n ==1){
        result = 1;
    }
    else{
        result = fibonacci_memo(n - 1, memo) + fibonacci_memo(n - 2, memo);
        memo[n] = result;
    }
    return result;
}

int main(){
    int position = 6; //Position in Fibonacci sequence to compute
    int fibNumber = fibonacci(position);
    printf("Fibonacci number at position %d is %d\n", position, fibNumber);
    

    int memo[10];  // Array to store previously computed Fibonacci numbers
    for (int i = 1; i < 10; i++) {  // Initialize all entries to -1 (not computed)
        memo[i] = -1;
    }
    int fibNumberMemo = fibonacci_memo(position, memo);
    printf("Fibonacci number at position %d with memoization is %d\n", position, fibNumberMemo);
    return 0;
}