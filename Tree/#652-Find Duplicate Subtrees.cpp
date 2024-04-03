// M1
// Using hashmap, imagine the string representation of the tree
// Faster than 55.78% (22 ms)

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
    unordered_map<string, int> mp;
    vector<TreeNode *> res;
    string duplicate(TreeNode *root)
    {
        if (!root)
            return "*";

        string leftStr = duplicate(root->left);
        string rightStr = duplicate(root->right);

        string curr = to_string(root->val) + "*" + leftStr + "*" + rightStr;

        if (mp[curr] == 1)
            res.push_back(root);
        mp[curr]++;
        return curr;
    }
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        duplicate(root);
        return res;
    }
};