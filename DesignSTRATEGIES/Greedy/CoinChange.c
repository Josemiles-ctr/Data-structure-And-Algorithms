#include <stdio.h>

// Greedy Coin Change Algorithm
void coinChange(int amount, int coins[], int n) {
    printf("Amount to change: %d\n", amount);
    printf("Available coins: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", coins[i]);
    }
    printf("\n\n");
    
    printf("Coins used:\n");
    int totalCoins = 0;
    
    // Iterate through each coin denomination (largest first)
    for (int i = 0; i < n; i++) {
        if (amount >= coins[i]) {
            int count = amount / coins[i];  // How many of this coin
            amount = amount % coins[i];     // Remaining amount
            
            printf("%d x %d = %d\n", count, coins[i], count * coins[i]);
            totalCoins += count;
        }
    }
    
    printf("\nTotal coins used: %d\n", totalCoins);
    
    if (amount > 0) {
        printf("Remaining amount that cannot be changed: %d\n", amount);
    }
}

int main() {
    // Test Case 1: Standard denominations (sorted largest to smallest)
    int coins1[] = {100, 50, 20, 10, 5, 2, 1};
    int n1 = sizeof(coins1) / sizeof(coins1[0]);
    int amount1 = 289;
    
    printf("ATM Cash Withdrawal\n");
    coinChange(amount1, coins1, n1);
    
    printf("\n");
    for (int i = 0; i < 40; i++) printf("=");
    printf("\n\n");
    return 0;
}
