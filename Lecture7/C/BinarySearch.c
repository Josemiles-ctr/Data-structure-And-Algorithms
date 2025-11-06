// Binary Search using Divide and Conquer (recursive)
#include <stdio.h>
int binarySearch(int arr[], int left, int right, int x) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if middle element is the target
        if (arr[mid] == x)
            return mid;

        // If target is smaller, search left half
        if (arr[mid] > x)
            return binarySearch(arr, left, mid - 1, x);

        // If target is larger, search right half
        return binarySearch(arr, mid + 1, right, x);
    }

    // Element not found
    return -1;
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("enter the element to be searched: ");
    int x = 0;
    scanf("%d", &x);

    int result = binarySearch(arr, 0, n - 1, x);

    if (result != -1)
        printf("Element %d found at index %d\n", x, result);
    else
        printf("Element %d not found in the array\n", x);

    return 0;
}
