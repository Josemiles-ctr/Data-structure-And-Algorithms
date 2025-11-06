package Lecture2.Jav;
public class MinEleAndIndex {                 
    public void MinEleAndIndex(int[] arr) {
        int minElement = arr[0];
        int minIndex = 0;

        for (int i = 1; i < arr.length; i++) {
            if (arr[i] < minElement) {
                minElement = arr[i];
                minIndex = i;
            }
        }

        System.out.println("Minimum Element: " + minElement);
        System.out.println("Index of Minimum Element: " + minIndex);
    }
    public static void main(String[] args) {
        MinEleAndIndex mei = new MinEleAndIndex();
        int[] sampleArray = {3, 5, 7, 2, 8, 6};
        mei.MinEleAndIndex(sampleArray);
    }
    
}
