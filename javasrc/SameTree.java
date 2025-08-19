package javasrc;

import javasrc.TreeNode;

class SameTree {
    static boolean sameTree(TreeNode root1, TreeNode root2) {
        if(root1 == null && root2 == null) return true;
        if(root1 == null || root2 == null) return false;
        if(root1.val != root2.val) return false;

        return sameTree(root1.left, root2.left) && sameTree(root1.right, root2.right);
    }

    public static void main(String[] args) {
        TreeNode root1 = new TreeNode(1);
        root1.left = new TreeNode(2);
        root1.right = new TreeNode(3);

        TreeNode root2 = new TreeNode(1);
        root2.left = new TreeNode(2);
        root2.right = new TreeNode(3);

        System.out.println(sameTree(root1, root2)); // Output: true

        root2.right.val = 4;
        System.out.println(sameTree(root1, root2)); // Output: false
    }
}