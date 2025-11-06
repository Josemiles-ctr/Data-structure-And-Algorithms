public class Selection {
    public static void main(String[] args) {
        int[] array = {6,2,5,1,7,3,9,8,4}; //The unsorted array

        selection(array);

        for(int i : array){
            System.out.print(i + " ");
        }
    }

    private static void selection(int[] array) {
        for (int i = 0; i < array.length - 1; i++) {
            int min = i;   //track the minimum value
            for (int j = i + 1; j < array.length ; j++) {
                if(array[j] < array[min]){
                    min = j;
                }
            }

            //Swap
            int temp = array[i];
            array[i] = array[min];
            array[min] = temp;
        }
    }
}
