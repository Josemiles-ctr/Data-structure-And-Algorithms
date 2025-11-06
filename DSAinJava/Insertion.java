public class Insertion {
    public static void main(String[] args) {
        int[] array = {6,2,5,1,7,3,9,8,4}; //The unsorted array

        insertion(array);

        for(int i : array){
            System.out.print(i + " ");
        }
    }

    private static void insertion(int[] array) {
        for (int i = 1; i < array.length ; i++) {
            int temp = array[i];
            int j = i - 1;

            while(j >= 0 && array[j] > temp){
                array[j+1] = array[j];
                j--;
            }

            array[j + 1 ] = temp;
        }
    }
}
