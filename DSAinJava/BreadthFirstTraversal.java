import java.util.LinkedList;
import java.util.Queue;

public class BreadthFirstTraversal {
    //We shall have the method for traversal
    public static void breadthFirstTraversal(Node root){
        if (root == null){
            return;   //Exit at a leaf
        }

        //Create a queue instance
        Queue<Node> queue = new LinkedList<>();

        // Start with the root node
        queue.add(root);

        // Loop until queue is empty
        while (!queue.isEmpty()) {
            Node current = queue.poll();  // dequeue front node
            System.out.print(current.data + " ");

            // Enqueue left child
            if (current.left != null) {
                queue.add(current.left);
            }

            // Enqueue right child
            if (current.right != null) {
                queue.add(current.right);
            }
        }


    }


    public static void main(String[] args) {

        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);
        root.right.right = new Node(6);

        System.out.print("Breadth-First Traversal (Level Order): ");
        breadthFirstTraversal(root);
    }
}
