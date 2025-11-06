#include <stdio.h>

//Attempt to merge two unsorted arrays into one

int main(){

    int arr1[] = {1,2,3,5}; // First 4 prime numbers
    int arr1Size = 4;       //Size of arr1

    int arr2[] = {7,11,13,17}; // Next 4 prime numbers
    int arr2Size = 4;       //Size of arr2

    int arr3[8]; //The resultant array
    int arr3Size = 8;       //Size of arr3

    int i = 0; //Target for arr1
    int j = 0; //Target for arr2
    int k = 0; //Target for arr3

    while(i < arr1Size){
        arr3[k] = arr1[i];   //Adding the elements of the first array
        i++; k++;
    }

    while(j < arr2Size){
        arr3[k] = arr2[j];   //Adding the elements of the secong array
        j++; k++;
    }

    printf("Our resulatant array\n");
    for(int i = 0; i < arr3Size; i++){
        printf("%d,",arr3[i]);
    }
    
    
    

    return 0;
}