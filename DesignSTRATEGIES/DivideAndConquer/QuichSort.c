#include <stdio.h>

// Swap function
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        
        quickSort(arr, low, pi - 1);  // Sort left of pivot
        quickSort(arr, pi + 1, high); // Sort right of pivot
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
    
    quickSort(arr, 0, size - 1);
    
    printf("\nSorted array:\n");
    printArray(arr, size);

    return 0;
}
