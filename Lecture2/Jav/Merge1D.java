package Lecture2.Jav;
import  java.util.Arrays;
@SuppressWarnings("all")
public class Merge1D {
    public void Merge1D(int[] arr1, int[] arr2) {
        int[] merged = new int[arr1.length + arr2.length];
        System.arraycopy(arr1, 0, merged, 0, arr1.length);
        System.arraycopy(arr2, 0, merged, arr1.length, arr2.length);
        Arrays.sort(merged);
        System.out.println("Merged and Sorted Array: " + Arrays.toString(merged));
    }
    public static void main(String[] args) {
        Merge1D merger = new Merge1D();
        int[] array1 = {1, 3, 5};
        int[] array2 = {2, 4, 6};
        merger.Merge1D(array1, array2);
    }   
}
