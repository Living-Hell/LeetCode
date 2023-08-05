// M1
// Using Divide and Conquer through recursion
// Faster than 91.6% (12 ms)

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
    vector<TreeNode *> helper(int left, int right)
    {
        if (left > right)
            return {NULL};
        vector<TreeNode *> temp;
        for (int i = left; i <= right; i++)
        {
            vector<TreeNode *> l = helper(left, i - 1);
            vector<TreeNode *> r = helper(i + 1, right);
            for (auto lnode : l)
            {
                for (auto rnode : r)
                {
                    TreeNode *root = new TreeNode(i, lnode, rnode);
                    temp.push_back(root);
                }
            }
        }
        return temp;
    }
    vector<TreeNode *> generateTrees(int n)
    {
        return helper(1, n);
    }
};