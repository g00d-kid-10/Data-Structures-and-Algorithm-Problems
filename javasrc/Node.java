package javasrc;


import java.util.ArrayList;
import java.util.List;

class Node {
    private int val;
    private List<Node> neighbours;

    Node() {this.val = 1; this.neighbours = new ArrayList<>();}
    Node(int _val) {this.val = _val; this.neighbours = new ArrayList<>();}
    Node(int _val, List<Node> _neighbours) {this.val = _val; this.neighbours = new ArrayList<>(_neighbours);}

    public static void main(String[] args) {
        Node node1 = new Node(1);
        Node node2 = new Node(2);
        node1.neighbours.add(node2);
        System.out.println("Node 1 value: " + node1.val); // Output: Node 1 value: 1
        System.out.println("Node 1 neighbour value: " + node1.neighbours.get(0).val); // Output: Node 1 neighbour value: 2
    }
}