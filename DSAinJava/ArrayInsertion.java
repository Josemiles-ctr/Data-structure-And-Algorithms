public class ArrayInsertion {
    // Attempt to insert a value into an array
    public static void main(String[] args) {
        int[] numbers = new int[7]; // The array of size 7
        numbers[0] = 23;
        numbers[1] = 2;
        numbers[2] = 56;
        numbers[3] = 34;
        numbers[4] = 13;

        int size = 7; //Size of the array
        int n = 5; // number of elements in the array
        int i; //The target

        int location = 2; //Insertion location
        int value = 18; //Insertion value

        System.out.println("Array before insertion");
        for (int a = 0; a < n; a++) {
            System.out.print(numbers[a] + ",");
        }
        if(size <= n){
            System.out.println("The array is full. No insertion allowed");
        }
        else {
            i = n - 1; //Start from the last element index
            while (i >= location) {
                numbers[i + 1] = numbers[i]; //Push values until the location
                i--;
            }
            numbers[location] = value; //Insert the value at the location
            n = n + 1;
        }

        System.out.println("\nArray after insertion");
        for (int a = 0; a < n; a++) {
            System.out.print(numbers[a] + ",");
        }
    }
}
