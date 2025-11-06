import java.util.LinkedList;
import java.util.Queue;

public class queue {
    //We shall model queues
    public static void main(String[] args) {
        //Queue is not a class, its an interface so we cant instantiate it
        //We will use a linked list that implements Queue interface

        Queue<String> queue = new LinkedList<>();

        queue.offer("Aburek");
        queue.offer("Otai");
        queue.offer("Praise");
        queue.offer("Victor");
        queue.offer("Doreck");

        //System.out.println(queue.poll());

//        queue.poll();
//        queue.poll();
//        queue.poll();
//        queue.poll();
//        queue.poll();



        System.out.println(queue.size());
        System.out.println(queue.isEmpty());
        System.out.println( queue.contains("Praise"));

        System.out.println(queue);
    }
}
