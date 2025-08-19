package javasrc;

class ListNode {
    int val;
    ListNode next;

    ListNode() {this.val = 0; this.next = null;}
    ListNode(int val) {this.val = val; this.next = null;}
    ListNode(int val, ListNode next) {this.val = val; this.next = next;}
    
    public static void main(String[] args) {
        ListNode node1 = new ListNode(1);
        ListNode node2 = new ListNode(2, node1);
        System.out.println("Node 2 value: " + node2.val); // Output: Node 2 value: 2
        System.out.println("Next node value: " + node2.next.val); // Output: Next node value: 1
    }
}