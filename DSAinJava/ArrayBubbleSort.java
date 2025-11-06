public class ArrayBubbleSort
{
    public static void main(String[] args) {
        //Attempt to bubble sort an array in ascending order
        int[] numbers = {23,2,56,34,13};  //The unordered array
        int U = 4; //Upper index of the array
        int L = 0; //Lower index of the array

        System.out.println("Array before sort");
        for(int num : numbers){
            System.out.print(num + ",");
        }

        for (int i = L; i < U - 1 ; i++) {  // This is for the number of scans on the array
            //This will cater of the iterations
            for (int j = 0; j < U - 1; j++)
                if (numbers[j] > numbers[j + 1]) { //Any unordered pair
                    int temp = numbers[j];
                    numbers[j] = numbers[j+1];   //The classic swap
                    numbers[j+1]  = temp;
                }
        }

        System.out.println("\nArray after sort");
        for(int num : numbers){
            System.out.print(num + ",");
        }
    }
}
