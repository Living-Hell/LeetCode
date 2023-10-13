// M1
// Using recursion
// Faster than 80.93% (7ms)

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
    TreeNode *solve(vector<int> &preorder, vector<int> &postorder, int &rind, int st, int end)
    {
        if (st > end or rind >= preorder.size())
            return NULL;

        TreeNode *root = new TreeNode(preorder[rind++]);

        if (st == end or rind == preorder.size())
            return root;

        int i;
        for (i = st; i <= end; i++)
        {
            if (postorder[i] == preorder[rind])
                break;
        }

        root->left = solve(preorder, postorder, rind, st, i);
        root->right = solve(preorder, postorder, rind, i + 1, end - 1);
        return root;
    }
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
    {
        int rind = 0;
        return solve(preorder, postorder, rind, 0, preorder.size() - 1);
    }
};