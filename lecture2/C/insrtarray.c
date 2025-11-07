#include <stdio.h>
int main(){
    int A[10]={1,2,3,4,5,7};
    int L=0,U=5,key,location;
    printf("Enter key to insert: ");
    scanf("%d",&key);
    printf("Enter location to insert at: ");
    scanf("%d",&location);
    if(U==9){
        printf("Array is full\n");
        return 0;
    }
    if(location<0||location>U+1){
        printf("Invalid location\n");
        return 0;
    }
    for(int i=U;i>=location;i--){
        A[i+1]=A[i];
    }
    A[location]=key;
    U++;
    printf("Array after insertion: ");
    for(int j=L;j<=U;j++){
        printf("%d ",A[j]);
    }
    printf("\n");
    return 0;
}