// M1
// Using recursion
// Faster than 99.6% (3ms)

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
    bool validBST(TreeNode *root, long long int curr_min, long long int curr_max)
    {
        if (!root)
            return 1;
        if (root->val > curr_min and root->val < curr_max and
            validBST(root->left, curr_min, root->val) and validBST(root->right, root->val, curr_max))
            return 1;
        return 0;
    }
    bool isValidBST(TreeNode *root)
    {
        return validBST(root, LONG_MIN, LONG_MAX);
    }
};