package javasrc;

import javasrc.TreeNode;

class IsValidBST {
    static boolean isValid(TreeNode node, long left, long right) {
        if(node == null) return true;
        if(!(left < node.val && node.val < right)) {
            return false;
        }
        return isValid(node.left, left, node.val) && isValid(node.right, node.val, right);
    }

    static boolean isValidBST(TreeNode root) {
        return isValid(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }

    public static void main(String[] args) {
        TreeNode root = new TreeNode(2);
        root.left = new TreeNode(1);
        root.right = new TreeNode(3);
        
        System.out.println(isValidBST(root));
    }
}