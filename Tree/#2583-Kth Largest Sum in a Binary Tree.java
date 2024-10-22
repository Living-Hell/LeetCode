//M1
//Using recursion and ArrayList
//Faster than 22.18% (41 ms)

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
    ArrayList<Long> lvlSum = new ArrayList<>();
    public void helper(TreeNode root, int lvl){
        if(root == null) return;
        if(lvl == lvlSum.size()) lvlSum.add((long) root.val);
        else lvlSum.set(lvl, lvlSum.get(lvl) + root.val);
        helper(root.left,lvl+1);
        helper(root.right,lvl+1);
    }
    public long kthLargestLevelSum(TreeNode root, int k) {
        helper(root,0);
        Collections.sort(lvlSum, Collections.reverseOrder());
        if(lvlSum.size() < k) return -1;
        return lvlSum.get(k-1);
    }
}
