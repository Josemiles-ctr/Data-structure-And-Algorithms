package Lecture2.Jav;
public class MaxEleAndIndex {
    public void getMaxEleAndIndex(int[] arr) {
        int maxElement = arr[0];
        int maxIndex = 0;

        for (int i = 1; i < arr.length; i++) {
            if (arr[i] > maxElement) {
                maxElement = arr[i];
                maxIndex = i;
            }
        }

        System.out.println("Maximum Element: " + maxElement);
        System.out.println("Index of Maximum Element: " + maxIndex);
    }
    public static void main(String[] args) {
        MaxEleAndIndex mei = new MaxEleAndIndex();
        int[] sampleArray = {3, 5, 7, 2, 8, 6};
        mei.getMaxEleAndIndex(sampleArray);
    }

}
