import java.util.Stack;

public class stack {
    //Attempt to represent the stack data structure
    public static void main(String[] args) {
        Stack<String> games = new Stack<>();
        games.push("FIFA17");
        games.push("Far Cry");
        games.push("COD");
        games.push("Mortal Combat");

        System.out.println(games.pop());

        System.out.println(games.peek());

        System.out.println(games);

        System.out.println(games.empty());





    }
}
