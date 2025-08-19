package javasrc;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode() {this.val = 0; this.left = null; this.right = null;}
    TreeNode(int val) {this.val = val; this.left = null; this.right = null;}
    TreeNode(int val, TreeNode left, TreeNode right) {this.val = val; this.left = left; this.right = right;}

    public static void main(String[] args) {
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        System.out.println("Root value: " + root.val); // Output: Root value: 1
        System.out.println("Left child value: " + root.left.val); // Output: Left child value: 2
        System.out.println("Right child value: " + root.right.val); // Output: Right child value: 3
    }   
}