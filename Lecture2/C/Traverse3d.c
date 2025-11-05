#include <stdio.h>

void traverse3D(int depth, int rows, int cols, int array[depth][rows][cols]) {
    for (int i = 0; i < depth; i++) {
        printf("Layer %d:\n", i + 1);
        for (int j = 0; j < rows; j++) {
            for (int k = 0; k < cols; k++) {
                printf("%d ", array[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}
int main() {
    int array3D[3][3][3] = {
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        },
        {
            {10, 11, 12},
            {13, 14, 15},
            {16, 17, 18}
        },
        {
            {19, 20, 21},
            {22, 23, 24},
            {25, 26, 27}
        }
    };
    
    traverse3D(3, 3, 3, array3D);
    return 0;
}