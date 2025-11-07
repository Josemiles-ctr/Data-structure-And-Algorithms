#include <stdio.h>
#include <stdlib.h>

// Merge two subarrays
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Create temporary arrays
    int* leftArr = (int*)malloc(n1 * sizeof(int));
    int* rightArr = (int*)malloc(n2 * sizeof(int));
    
    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }
    
    // Merge the temporary arrays back into arr[]
    int i = 0, j = 0, k = left;
    
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    // Copy remaining elements of leftArr[], if any
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    
    // Copy remaining elements of rightArr[], if any
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
    
    // Free temporary arrays
    free(leftArr);
    free(rightArr);
}

// Merge Sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        // Merge the sorted halves
        merge(arr, left, mid, right);
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
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 88, 45, 50, 23};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array:\n");
    printArray(arr, size);
    
    mergeSort(arr, 0, size - 1);
    
    printf("\nSorted array:\n");
    printArray(arr, size);
    
    // Additional test case
    int arr2[] = {5, 2, 9, 1, 7, 6, 3};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    printf("\nOriginal array 2:\n");
    printArray(arr2, size2);
    
    mergeSort(arr2, 0, size2 - 1);
    
    printf("Sorted array 2:\n");
    printArray(arr2, size2);
    
    return 0;
}
