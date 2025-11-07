#include <stdio.h>

int main()
{
    // Bubble sort an array in descending order
    int arr[] = {23,2,56,34,13};
    int U = 4; // The upper index of the array
    int L = 0; // The lower index of the array

    printf("Array before sort\t");
    for (int a = 0; a <= U; a++)
    {
        printf("%d,",arr[a]);
    }
    
    // Optimized bubble sort for descending order
    for(int i = L; i <= U; i++)  // Better condition
    {
        for (int j = L; j < U - i; j++)  // Optimized inner loop
        {
            if(arr[j] > arr[j+1])  
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("\nArray after sort\t");
    for (int a = 0; a <= U; a++)
    {
        printf("%d,",arr[a]);
    }

    return 0;
}