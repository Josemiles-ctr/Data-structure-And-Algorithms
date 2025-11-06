public class MergeSortedArrays {
    //Attempt to merge two sorted arrays into one

    public static void main(String[] args) {
        int[] A = {1,3,5,6,9}; //The first array
        int[] B = {2,4,8,10,11,12,13}; //The second array
        int sizeA = 5; //Size of array A
        int sizeB = 7; //Size of array B
        int sizeC = 5 + 12; //size of the resultant array C

        int[] C = new int[12]; //The resultant array C

        //Initialize the targets of the arrays
        int i = 0; // target for A
        int j = 0; // target for B
        int k = 0; // target for C

        System.out.println("Array A :");
        for(int element : A){
            System.out.print(element + ",");
        }

        System.out.println("\nArray B :");
        for(int element : B){
            System.out.print(element + ",");
        }

        while(i < sizeA && j < sizeB){ //Have to make sure that both targets and less than the Upper index during comparison
            if(A[i] < B[j]){
                C[k] = A[i];  //We compare the elements, the less element is moved to the
                i++;            //resultant and the target incremented
            }
            else{
                C[k] = B[j];
                j++;
            }
            k++;            //After an addition, the target of C is moved
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

        System.out.println("\nArray C :");
        for(int element : C){
            System.out.print(element + ",");
        }

    }

}
