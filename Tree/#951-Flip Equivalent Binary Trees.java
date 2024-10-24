//M1
//Using recursion
//Faster than 100% (0ms)

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean flipEquiv(TreeNode root1, TreeNode root2) {
        if(root1 == null && root2 == null) return true;
        if(root1 == null || root2 == null) return false;
        if(root1.val != root2.val) return false;

        Boolean check1 = false, check2 = false, check3 = false, check4 = false;

        check1 = flipEquiv(root1.left,root2.right);
        check2 = flipEquiv(root1.right,root2.left);

        if((root1.left != null && root2.left != null && root1.left.val == root2.left.val) || (root1.right != null && root2.right != null && root1.right.val == root2.right.val)){
            check3 = flipEquiv(root1.left,root2.left);
            check4 = flipEquiv(root1.right,root2.right);
        }

        if((check1 && check2) || (check3 && check4)) return true;

        return false;
    }
}
