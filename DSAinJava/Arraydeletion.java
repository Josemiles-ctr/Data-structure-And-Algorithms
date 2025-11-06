public class Arraydeletion {
    public static void main(String[] args) {
        int[] numbers = new int[7];  //The unfilled array
        numbers[0] = 23;
        numbers[1] = 2;
        numbers[2] = 56;
        numbers[3] = 34;
        numbers[4] = 13;

        int size = 7; //Size of the array
        int n = 5; //number of elements in the array
        int value = 56; //Value intended for deletion

        System.out.println("Array before deletion");
        for (int a = 0; a < n; a++) {
            System.out.print(numbers[a] + ",");
        }

        int index = search_array(numbers,value,n); //The index of the intended

        while (index < n){
            numbers[index] = numbers[index+1];
            index++;
        }
        n = n - 1;

        System.out.println("\nArray after deletion");
        for (int a = 0; a < n; a++) {
            System.out.print(numbers[a] + ",");
        }

    }

    public static int search_array(int[] arr, int target, int arrElements){
        int index = 0; //Holder of the intended's index
        for (int i = 0; i < arrElements; i++) {
            if (arr[i] == target){
                index = i;
            }
        }

        return index;
    }
}
