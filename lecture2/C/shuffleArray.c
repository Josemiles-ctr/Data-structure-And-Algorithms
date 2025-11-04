#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to shuffle an array in-place
void shuffleInPlace(int arr[], int n) {
    srand(time(NULL));  // Seed the random number generator

    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);  // Random index from 0 to i

        // Swap arr[i] and arr[j]
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    int data[] = {1, 2, 3, 4, 5};
    int n = sizeof(data) / sizeof(data[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    shuffleInPlace(data, n);

    printf("Shuffled array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    return 0;
}

