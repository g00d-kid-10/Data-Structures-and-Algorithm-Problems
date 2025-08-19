package javasrc;

class Node {
    private int val;
    private List<Node> neighbours;

    Node() {this.val = 1; this.neighbours = new ArrayList<>();}
    Node(int _val) {this.val = _val; this.neighbours = new ArrayList<>();}
    Node(int _val, List<Node> _neighbours) {this.val = _val; this.neighbours = new ArrayList<>(_neighbours);}
}