package javasrc;

import javasrc.TreeNode;

class IsSubTree {
    static boolean isSubTree(TreeNode root, TreeNode subRoot) {
        if(subRoot == null) return true;
        if(root == null) return false;

        if(sameTree(root, subRoot)) return true;
        return isSubTree(root.left, subRoot) || isSubTree(root.right, subRoot);
    }

    static boolean sameTree(TreeNode root1, TreeNode root2) {
        if(root1 == null && root2 == null) return true;
        if(root1 == null || root2 == null) return false;
        if(root1.val != root2.val) return false;

        return sameTree(root1.left, root2.left) && sameTree(root1.right, root2.right);
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(3, new TreeNode(4, new TreeNode(1), new TreeNode(2)), new TreeNode(5));
        TreeNode subRoot = new TreeNode(4, new TreeNode(1), null);
        System.out.println(isSubTree(root, subRoot)); // Output: false
    }
}