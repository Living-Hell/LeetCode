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
    void lvlOrderTraversal(TreeNode *root, vector<vector<int>> &ans, int lvl)
    {
        if (!root)
            return;

        if (ans.size() == lvl)
            ans.push_back({});
        ans[lvl].push_back(root->val);

        lvlOrderTraversal(root->left, ans, lvl + 1);
        lvlOrderTraversal(root->right, ans, lvl + 1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        lvlOrderTraversal(root, ans, 0);
        for (int i = 1; i < ans.size(); i += 2)
            reverse(ans[i].begin(), ans[i].end());
        return ans;
    }
};