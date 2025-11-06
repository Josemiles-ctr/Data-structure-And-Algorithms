// Merging two 1D arrays A and B into a third array C
#include <stdio.h>
int main(){
    int A[10]={1,2,3,4,5,6,7,8,9,10};
    int B[10]={11,12,13,14,15,16,17,18,19,20};
    int C[20];
    printf("Array A: ");
    for(int i=0;i<10;i++){//printing A
        printf("%d ",A[i]);
    }
    printf("\n");
    printf("Array B: ");
    for(int i=0;i<10;i++){//printing B
        printf("%d ",B[i]);
    }
    printf("\n"); 
    // Merging A and B into C
    int i,j;
    for(i=0;i<10;i++){//copying A to C
        C[i]=A[i];
    }
    for(j=0;j<10;j++){//copying B to C
        C[i+j]=B[j];
    }
    printf("Merged array: ");
    for(int k=0;k<20;k++){//printing C
        printf("%d ",C[k]);
    }
    printf("\n");
    return 0;
}