#include <stdio.h>

// Iterative Binary Search
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid;
        }
        
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return -1; // Element not found
}

// Recursive Binary Search
int binarySearchRecursive(int arr[], int target, int left, int right) {
    if (left > right) {
        return -1; // Base case: element not found
    }
    
    int mid = left + (right - left) / 2;
    
    if (arr[mid] == target) {
        return mid;
    }
    
    if (arr[mid] < target) {
        return binarySearchRecursive(arr, target, mid + 1, right);
    } else {
        return binarySearchRecursive(arr, target, left, mid - 1);
    }
}

// Helper function to print array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 67, 78};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array: ");
    printArray(arr, size);
    printf("\n");
    
    // Test iterative search
    int target1 = 23;
    int result1 = binarySearch(arr, size, target1);
    printf("Iterative Search:\n");
    printf("Target: %d\n", target1);
    printf("Result: %s\n\n", result1 != -1 ? "Found at index" : "Not found");
    if (result1 != -1) printf("Index: %d\n\n", result1);
    
    // Test recursive search
    int target2 = 45;
    int result2 = binarySearchRecursive(arr, target2, 0, size - 1);
    printf("Recursive Search:\n");
    printf("Target: %d\n", target2);
    printf("Result: %s\n", result2 != -1 ? "Found at index" : "Not found");
    if (result2 != -1) printf("Index: %d\n\n", result2);
    
    // Test with non-existent element
    int target3 = 100;
    int result3 = binarySearch(arr, size, target3);
    printf("Search for non-existent element:\n");
    printf("Target: %d\n", target3);
    printf("Result: %s\n", result3 != -1 ? "Found at index" : "Not found");
    if (result3 != -1) printf("Index: %d\n", result3);
    
    return 0;
}
