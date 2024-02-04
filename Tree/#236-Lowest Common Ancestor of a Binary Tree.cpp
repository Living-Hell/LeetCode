// M1
// Using Recursion
// Faster than 32.44% (17 ms)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    bool find(TreeNode *root, TreeNode *target)
    {
        if (!root)
            return 0;
        if (root == target)
            return 1;
        if (find(root->left, target) or find(root->right, target))
            return 1;
        return 0;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return NULL;
        TreeNode *lNode = lowestCommonAncestor(root->left, p, q);
        TreeNode *rNode = lowestCommonAncestor(root->right, p, q);
        if (lNode)
            return lNode;
        if (rNode)
            return rNode;
        if (find(root, p) and find(root, q))
            return root;
        return NULL;
    }
};