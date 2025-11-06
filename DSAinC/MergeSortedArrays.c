#include <stdio.h>
//Atempt to merge two sorted arrays into one

int main(){

    int A[] = {1,3,5,6,9}; //The first array
    int B[] = {2,4,8,10,11,12,13}; //The second array
    int sizeA = 5; //Size of array A
    int sizeB = 7; //Size of array B
    int sizeC = 5 + 7; //Size of array C

    printf("Array A :");
    for (int a = 0; a < sizeA; a++)
    {
        printf("%d,",A[a]);
    }

    printf("\nArray B :");
    for (int b = 0; b < sizeB; b++)
    {
        printf("%d,",B[b]);
    }
    

    int C[12]; //The resutant array

    //Initialize the targets for the three array
    int i = 0; //Target for array A
    int j = 0; //Target for array B
    int k = 0; //Target for array C

    while (i < sizeA && j < sizeB) //Have to make sure that both targets are less than the Upper index during comparison
    {
        if(A[i] < B[j]){
            C[k] = A[i];  //We compare the elements, the less element is moved to the
            i++;            //resultant and the target incremented
        }
        else{
            C[k] = B[j];
            j++;
        }
        k++;  //After an addition, the target of C is moved
    }
    
    //Copy any remaining elements from A
    while (i < sizeA)
    {
        C[k] = A[i];
        i++; k++;
    }

    //Copy any remaining elements from B
    while (j < sizeB)
    {
        C[k] = B[j];
        j++; k++;
    }
    
    printf("\nArray C :");
    for (int c = 0; c < sizeC; c++)
    {
        printf("%d,",C[c]);
    }

    return 0;
}