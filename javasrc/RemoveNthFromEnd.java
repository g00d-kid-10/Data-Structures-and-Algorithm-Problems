package javasrc;

import javasrc.ListNode;

class RemoveNthFromEnd {
    static ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode temp = head;
        while(temp.next != null) {
            ListNode rHead = reverseList(temp.next);
            temp.next = rHead;
            temp = temp.next;
        }

        return head;
    }

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
        // This code needed to be verified
    }
}
