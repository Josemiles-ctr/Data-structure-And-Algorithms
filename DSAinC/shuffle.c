#include <stdio.h>
#include <stdlib.h>
#include <time.h>     //Libraries required for creating a random number

//Attempt to use the Fisher-Yates algorithm to shuffle an array

int main(){

    int numbers[] = {1,2,3,4,5,6,7,8,9};   //This the shuffled array
    int size = 9;  //Size of the array

    srand(time(0));   //Seed for the random numbers

    for(int i =size - 1; i > 0; i-- ){ 
        /*We want the target to seperate the array into the shuffled and unshuffled part. 
        We shall start from the last index, create a random index for the unshuffled part
        Swap the value in that index with thator the target index*/ 
        
        int j = rand() % (i + 1);   //We create a random value from the unshuffled indexes

        int temp = numbers[i];
        numbers[i] = numbers[j];    //The classic swap
        numbers[j] = temp;

        
    }


    printf("The shuffled array: \t");
    for(int i = 0; i < size; i++){
        printf("%d,",numbers[i]);
    }


    return 0;
}