// M1
// Using recursion (DP)
//  Faster than 98.3% (4ms)

class Solution
{
public:
    pair<int, int> helper(TreeNode *root)
    {
        if (!root)
            return {0, 0};
        pair<int, int> l = helper(root->left);
        pair<int, int> r = helper(root->right);
        return {root->val + l.second + r.second, max(l.first, l.second) + max(r.first, r.second)};
    }
    int rob(TreeNode *root)
    {
        pair<int, int> ans;
        ans = helper(root);
        return max(ans.first, ans.second);
    }
};