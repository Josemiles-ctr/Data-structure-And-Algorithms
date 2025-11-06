import java.util.LinkedList;

public class InsertLinked {
    //Attempt to insert values at the start, end an in between of linked list
    public static void main(String[] args) {

        LinkedList<Integer> numbers = new LinkedList<>();
        numbers.add(12);
        numbers.add(24);
        numbers.add(35);

        //Insert at the start
        numbers.addFirst(7);

        //Insert at the end
        numbers.addLast(54);

        //Insert at a point
        numbers.add(3,29);

        for(int num : numbers){
            System.out.print(num + "->");
        }
    }
}
