package javasrc;

import javasrc.TreeNode;

class KthSmallest {
    private TreeNode root;
    private int k;
    private int counter, ans;

    KthSmallest() {
        this.root = null;
        this.k = 0;
        this.counter = 0;
        this.ans = -1;
    }

    public void inOrder(TreeNode root) {
        if(root == null) return;
        inOrder(root.left);
        counter++;
        if(counter == k) {
            ans = root.val;
            return;
        }
        inOrder(root.right);
        return;
    }

    public int kthSmallest(TreeNode root, int k) {
        this.root = root;
        this.k = k;
        inOrder(root);
        return ans;
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(3);
        root.left = new TreeNode(1);
        root.right = new TreeNode(4);
        root.left.right = new TreeNode(2);

        KthSmallest kthSmallestFinder = new KthSmallest();
        int k = 5; // Find the 1st smallest element
        int result = kthSmallestFinder.kthSmallest(root, k);
        System.out.println("The " + k + "th smallest element is: " + result); // Output: 1
    }
}