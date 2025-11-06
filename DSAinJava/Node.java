public class Node {
    //This is the class used for constructing nodes
    int data;   //The value
    Node right; //The left child
    Node left;  //The right child

    public Node(int data){
        this.data = data;
        this.left = this.right = null;
    }
}
