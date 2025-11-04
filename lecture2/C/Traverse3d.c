//A program that traverses a 3D array and prints its elements with their indexes
#include <stdio.h>

int main() {
    int arr[2][2][2] = {
        {
            {1, 2},
            {3, 4}
        },
        {
            {5, 6},
            {7, 8}
        }
    };

    printf("Traversing 3D array with indices:\n\n");

    for (int i = 0; i < 2; i++) {          // plane index
        for (int j = 0; j < 2; j++) {      // row index
            for (int k = 0; k < 2; k++) {  // column index
                printf("arr[%d][%d][%d] = %d\n", i, j, k, arr[i][j][k]);
            }
        }
    }

    return 0;
}
