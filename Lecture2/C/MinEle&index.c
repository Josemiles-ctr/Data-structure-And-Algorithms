# include <stdio.h>
void getMinEle(int size, int array[], int *minEle, int *minIndex) {
    *minEle = array[0];
    *minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (array[i] < *minEle) {
            *minEle = array[i];
            *minIndex = i;
        }
    }
}
int main() {
    int array[] = {5, 2, 9, 1, 5, 6};
    int minEle, minIndex;
    getMinEle(sizeof(array) / sizeof(array[0]), array, &minEle, &minIndex);
    printf("Minimum Element: %d\n", minEle);
    printf("Minimum Index: %d\n", minIndex);
    return 0;
}