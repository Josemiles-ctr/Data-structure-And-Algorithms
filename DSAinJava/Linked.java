import java.util.LinkedList;

public class Linked {
    public static void main(String[] args) {
        //Creation of a linked list
        LinkedList<String> nameList = new LinkedList<>();
        nameList.add("Manuel");
        nameList.add("Joseph");
        nameList.add("Doreck");
        nameList.add("Praise");

        for(String name : nameList){
            System.out.println(name);
        }

    }
}
