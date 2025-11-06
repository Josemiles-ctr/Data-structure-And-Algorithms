#include <stdio.h>

//Attempt to create and traverse a single, 2D and 3D array and get their base addresses
//The base address of an array is the address of the first element of an array

int main(){

    int single[] = {1,2,3,4,5};  //Single dimensional array

    int _2D[2][3] = {
                        {1,2,3},   //2D array
                        {4,5,6} 
                    };

    int _3D[2][2][3] = {
        {
            {1,2,3},
            {4,5,6}
        },                          //3D array
        {
            {7,8,9},
            {10,11,12}
        }
    };


    //for 1 D
    for(int i=0; i < 5; i++){
        printf("%d,",single[i]);
    }
    printf("The base address of 1D array is %d\n",single);

    //for 2 D
    for(int i=0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            printf("%d,",_2D[i][j]);
        }
        
    }
    printf("The base address of 2D array is %d\n",_2D);

    //for 3 D
    for(int i=0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 3; k++){
                printf("%d,",_3D[i][j][k]);
            }
        }
    }
    printf("The base address of 3D array is %d\n",_3D);

    return 0;
}