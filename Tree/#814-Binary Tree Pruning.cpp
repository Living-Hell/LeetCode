// M1
// Using recursion
// Faster than 100% (0ms)

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
    TreeNode *solve(TreeNode *root)
    {
        if (!root)
            return NULL;
        if (!root->right and !root->left and root->val == 0)
            return NULL;
        root->left = solve(root->left);
        root->right = solve(root->right);
        if (!root->right and !root->left and root->val == 0)
            return root = NULL;
        return root;
    }
    TreeNode *pruneTree(TreeNode *root)
    {
        return solve(root);
    }
};