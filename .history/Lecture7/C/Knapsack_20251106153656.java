
import java.util.*;

public class Knapsack{
    public static void main(String[] args) {
        //Attempt to implement fractional knapsack with dynamic programing
        double[] value = {60, 100, 120};  //Value of items
        double[] weight = {10, 20, 30};   //Weights of items
        double capacity = 50;

        int n = value.length;

        //Compute the value/weight ratio
        double[] ratio = new double[n];
        for(int i = 0; i < n; i++){
            ratio[i] = value[i] / weight[i];
        }
    }


    //Sort items by value/weight ratio in descending order
    for(int i = 0; i < n; i++){
        for(int j = i+1; j<n ; j++){

            if(ratio[i] < ratio[j]){
                //Swap ratios
                double temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                //Swap values
                double tempVal = value[j];
                value[i] = value[j];
                value[j] = tempVal;

                //Swap weight
                double tempWit = weight[i];
                weight[i] = weight[j];
                weight[j] = tempWit;
            }
        }
    }

    

}