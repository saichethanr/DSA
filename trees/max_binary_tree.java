package trees;



class Treenode {
     int val;
     Treenode left;
     Treenode right;
     Treenode() {}
     Treenode(int val) { this.val = val; }
     Treenode(int val, Treenode left, Treenode right) {
         this.val = val;
         this.left = left;
         this.right = right;
     }
 }


public class max_binary_tree {
    public  static void main(String [] args){
        int [] arr = {3,2,1,6,0,5};

       Treenode head = constructMaximumBinaryTree(arr);
       inorderTraversal(head);
    }

    public static Treenode constructMaximumBinaryTree(int[] nums) {
         return solve(nums,0,nums.length-1);
    }

    public static Treenode solve(int [] nums,int start,int end){
        if(start>end){
            return null;
        }
        int maxind = findmaxind(nums,start,end);

        Treenode root = new Treenode(nums[maxind]);

        root.left = solve(nums,start,maxind-1);
        root.right = solve(nums,maxind+1,end);

        return root;
    }

    private static int findmaxind(int[] nums, int start, int end) {

            int max = Integer.MIN_VALUE;
            int ind = -1;
            for(int i=start;i<=end;i++){
                if(nums[i]>max){
                    max = nums[i];
                    ind =i;
                }
            }

        return ind;
    }

    public static void inorderTraversal(Treenode root) {
        if (root == null) return;
        inorderTraversal(root.left);
        System.out.print(root.val + " ");
        inorderTraversal(root.right);
    }
}
