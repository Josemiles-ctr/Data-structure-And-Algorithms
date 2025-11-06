#include <stdio.h>

int search_array(int arr[], int intendedValue, int arrElements); // Function prototype

int main(){
    //Attempt to delete a value from an array
    int numbers[7] = {23,2,56,34,13};  // Unfilled array
    int size = 7; // The size of the array
    int n = 5; //Number of elements in the array
    int value = 56; // Value intended for deletion
    int index = search_array(numbers,value,n); // The index of the element intended for deletion

     printf("Array before deletion \t");
    for(int a = 0; a < n; a++){
        printf("%d,",numbers[a]);
    }

    if(index == -1){
        printf("Value not found, deletion is impossible");
    }
    else{
        int i= index; //The target

        while (i < n)
        {
            numbers[i] = numbers[i+1];  //progressively filling the deletion gao
            i++;
        }
        n = n - 1;
    }   

     printf("Array after deletion \t");
    for(int a = 0; a < n; a++){
        printf("%d,",numbers[a]);
    }
    
    return 0;
}

int search_array(int arr[], int intendedValue, int arrElements){
    //Attempt to search through an array for a value and return its index
    int index;  // Holder of the intended value's index

    for(int i = 0; i < arrElements; i++){
        if(arr[i] == intendedValue){   //Acquire the index of the intended element
            index = i;
        }
    }

    return index;
}