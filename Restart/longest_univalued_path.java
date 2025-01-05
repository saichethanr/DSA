package Restart;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}


public class longest_univalued_path {
    public static void main(String [] args){


    }

    public static int solve(TreeNode root){
        if(root.left.val==root.val){
            return solve(root.left)+1;
        }
        if(root.right.val==root.val){
            return solve(root.right)+1;
        }
        return Math.max(solve(root.left),solve(root.right));
    }
}
