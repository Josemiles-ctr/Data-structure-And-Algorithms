# include <stdio.h>
void maxEleAndIndex(int size, int array[], int *maxEle, int *maxIndex) {
    *maxEle = array[0];
    *maxIndex = 0;
    for (int i = 1; i < size; i++) {
        if (array[i] > *maxEle) {
            *maxEle = array[i];
            *maxIndex = i;
        }
    }
}   
int main() {
    int array[] = {5, 2, 9, 1, 5, 6};
    int maxEle, maxIndex;
    maxEleAndIndex(sizeof(array) / sizeof(array[0]), array, &maxEle, &maxIndex);
    printf("Maximum Element: %d\n", maxEle);
    printf("Maximum Index: %d\n", maxIndex);
    return 0;
}