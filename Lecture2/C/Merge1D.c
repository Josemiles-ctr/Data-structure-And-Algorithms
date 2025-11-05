#include <stdio.h>
void merge1D(int size1, int array1[], int size2, int array2[], int mergedArray[]) {
    int i = 0, j = 0, k = 0;

    // Merge the two arrays
    while (i < size1 && j < size2) {
        if (array1[i] < array2[j]) {
            mergedArray[k++] = array1[i++];
        } else {
            mergedArray[k++] = array2[j++];
        }
    }

    // Copy remaining elements from array1, if any
    while (i < size1) {
        mergedArray[k++] = array1[i++];
    }

    // Copy remaining elements from array2, if any
    while (j < size2) {
        mergedArray[k++] = array2[j++];
    }
}
int main() {
    int array1[] = {1, 3, 5};
    int array2[] = {2, 4, 6};
    int mergedArray[6];

    merge1D(sizeof(array1) / sizeof(array1[0]), array1,
            sizeof(array2) / sizeof(array2[0]), array2,
            mergedArray);

    // Print the merged array
    for (int i = 0; i < 6; i++) {
        printf("%d ", mergedArray[i]);
    }
    printf("\n");

    return 0;
}