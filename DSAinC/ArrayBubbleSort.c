#include <stdio.h>

int main()
{
    //Attempt to bubble sort an array in ascending order

    int arr[] = {23,2,56,34,13};  //The unordered array
    int U = 4; // The upper index of the array
    int L = 0; // The lower index of the array

    printf("Array before sort\t");
    for (int a = 0; a <= U; a++)
    {
        printf("%d,",arr[a]);
    }
    

    for(int i = L; i < U - 1; i++)  // This will cater for the number of scans
    {
        for (int j = L; j < U - 1; j++)  //This will cater for the iterations in one scan
        {
            if(arr[j] > arr[j+1])  //For an ordered pair
            {
                int temp = arr[j];
                arr[j+1] = arr[j];   //The classic swap
                arr[j+1]  = temp;
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