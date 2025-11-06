public class ComputingTime {
    public static void main(String[] args) {
        //Attempt to determine computing time

        int m = 2;
        int n = 5;
        int p; //Hold the product of 2 and 5
        int time; // Hold the time per operation

        time = 0;
        p = 0;
        time++;
        for (int i = 0; i < n ; i++) {
            time = time + 3;
            p = p + m;
            time = time + 2;
        }

        System.out.println("The product is: "+ p);
        System.out.println("It took " + time + " unit of time");


    }
}
