#include <stdio.h>

int main(){

    // An algorithm to insert value 18 at index 2 in the numbers array

    int numbers[7] = {23,2,56,34,13};  //The unfilled array
    int L = 0; // The lower index
    int U = 6; // The upper index
    int n = 5; //The number of elements in the array
    int size = 7; //Size of the array

    int i; // The target
    int location = 2; // insertion index
    int value = 18; // insertion value

     printf("Array before insertion \t");
    for(int a = 0; a < n; a++){
        printf("%d,",numbers[a]);
    }

    printf("\n");

    if(size <= n ){
        printf("The array is full. Insertion not possible");  // Check if array is filled
    }
    else{
        i = n - 1;  //start at the index of the last value
        while(i >= location){
            numbers[i+1] = numbers[i];  // Push elements until the location
            i = i-1;
        }
        numbers[location] = value;      //Insert vale
        n = n + 1;                      // Increase the upper index
    }

    printf("Array after insertion \t"); 
    for(int a = 0; a < n; a++){ 
        printf("%d,",numbers[a]);
    }

    return 0;
}