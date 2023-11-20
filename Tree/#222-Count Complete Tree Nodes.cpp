// M1
// Using recursion and height of tree
// Faster than 26.72% (29 ms)

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
    int lheight(TreeNode *root)
    {
        if (!root)
            return 1;
        return 1 + lheight(root->left);
    }
    int rheight(TreeNode *root)
    {
        if (!root)
            return 1;
        return 1 + rheight(root->right);
    }
    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;
        int l = lheight(root->left), r = rheight(root->right);
        if (l == r)
            return pow(2, l) - 1;
        else
            return 1 + countNodes(root->left) + countNodes(root->right);
    }
};