package Lecture2.Jav;

public class Traverse3D {
    public void traverse3D(int[][][] matrix) {
        System.out.println("Traversing 3D Array:");
        for (int i = 0; i < matrix.length; i++) {
            System.out.println("Layer " + (i + 1) + ":");
            for (int j = 0; j < matrix[i].length; j++) {
                for (int k = 0; k < matrix[i][j].length; k++) {
                    System.out.print(matrix[i][j][k] + " ");
                }
                System.out.println();
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Traverse3D traverser = new Traverse3D();
        int[][][] sampleMatrix = {
            {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}
            },
            {
                {10, 11, 12},
                {13, 14, 15},
                {16, 17, 18}
            },
            {
                {19, 20, 21},
                {22, 23, 24},
                {25, 26, 27}
            }
        };
        traverser.traverse3D(sampleMatrix);
    }
    
}
