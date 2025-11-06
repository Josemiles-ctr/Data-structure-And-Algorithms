#include <stdio.h>

//Attempt to create functions to determine the minimum and maximum values of a 2D array

int main(){

    int arr[2][3] = {
                        {2,4,6},    //The 2D array
                        {8,10,12}
                    };

    int max = arr[0][0];  //The placeholder for current maximum value                

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            if(arr[i][j] > max){    // We campare two at a time
                max = arr[i][j];
            }
        }
    }

    printf("The maximum value is %d",max);

    int min = arr[0][0];  //The placeholder for current minimum value 

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            if(arr[i][j] < min){    // We campare two at a time
                min = arr[i][j];
            }
        }
    }


    printf("The minimum value is %d",min);


    return 0;
}