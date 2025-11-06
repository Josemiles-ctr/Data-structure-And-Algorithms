package Lecture2.Jav;

public class Traverse2d {
    public void traverse2D(int[][] matrix) {
        System.out.println("Traversing 2D Array:");
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Traverse2d traverser = new Traverse2d();
        int[][] sampleMatrix = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        };
        traverser.traverse2D(sampleMatrix);
    }
    
}
