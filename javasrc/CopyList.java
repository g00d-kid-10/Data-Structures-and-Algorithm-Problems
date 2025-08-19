package javasrc;

import javasrc.ListNode;

class CopyList {
    static ListNode copyList(ListNode head) {
        ListNode dummy = new ListNode();
        ListNode temp = dummy;
        while(head != null) {
            temp.next = new ListNode(head.val);
            temp = temp.next; head = head.next;
        }

        return dummy.next;
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
        ListNode copyList = copyList(root);
        printList(copyList);
    }
}