// M1
// Using Recursion
// Faster than 41.92% (31ms)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    void solve(TreeNode *root, int par, int gpar, int &sum)
    {
        if (!root)
            return;

        if (gpar % 2 == 0)
            sum += root->val;

        solve(root->left, root->val, par, sum);
        solve(root->right, root->val, par, sum);
    }
    int sumEvenGrandparent(TreeNode *root)
    {
        int sum = 0;
        solve(root, -1, -1, sum);
        return sum;
    }
};