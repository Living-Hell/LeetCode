// M1
// Using recursion
// Faster than 39.36% (65ms)

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
    TreeNode *insert(TreeNode *root, int val)
    {
        if (!root)
            return new TreeNode(val);

        if (val < root->val)
            root->left = insert(root->left, val);
        if (val > root->val)
            root->right = insert(root->right, val);

        return root;
    }
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        return insert(root, val);
        ;
    }
};