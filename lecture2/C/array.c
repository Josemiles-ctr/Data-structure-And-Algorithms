#include <stdio.h>
int main(){
    int a[3]={1,2,3};
    int b[3]={5,6,7};
    int c[6];
    int location, u,L,key;
    int i,j;
    for(i=0; i<3; i++){
        c[i]=a[i];
    }
    for(j=0; j<3;j++){
        c[i+j]=b[j];
    }
    printf("Merged array: ");
    for(int k=0;k<6;k++){//printing C
        printf("%d ",c[k]); 
}
    printf("\n");
    //deleting from an array
    printf("\nEnter value to delete: ");
    scanf("%d", &key);
    
    int size = 6; // Current size of array
    int found = 0; // Flag to check if element was found
    
    // Search for the element to delete
    for(int k = 0; k < size; k++) {
        if(c[k] == key) {
            location = k;
            found = 1;
            
            // Shift elements to the left
            for(int m = location; m < size - 1; m++) {
                c[m] = c[m + 1];
            }
            size--; // Reduce array size
            break; // Exit after deleting first occurrence
        }
    }
    
    if(found) {
        printf("Array after deletion: ");
        for(int k = 0; k < size; k++) {
            printf("%d ", c[k]);
        }
    } else {
        printf("Element %d not found in array!\n", key);
    }
    
    return 0;
}