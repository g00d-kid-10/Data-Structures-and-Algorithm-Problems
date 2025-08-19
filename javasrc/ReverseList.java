package javasrc;

import javasrc.ListNode;

class ReverseList {
    static ListNode reverseList(ListNode head) {
        if(head.next == null) return head;
        ListNode temp = reverseList(head.next);
        head.next.next = head;
        head.next = null;

        return temp;
    }

    static void printList(ListNode head) {
        ListNode temp = head;
        
        while(temp != null) {
            System.out.print(temp.val + " ");
            temp = temp.next;
        }

        System.out.println();
    }


    public static void main(String[] args) {
        ListNode root = new ListNode(4, new ListNode(7, new ListNode(11, null)));
        ListNode reversedList = reverseList(root);
        printList(reversedList);
    }
}