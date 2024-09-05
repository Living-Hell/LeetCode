//M1
//Using hashmap and lambda function to sort
//Faster than 72.67% (3ms)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, map<int, vector<vector<int>>>& mp, int col, int row) {
        if (!root)
            return;
        solve(root->left, mp, col - 1, row + 1);
        solve(root->right, mp, col + 1, row + 1);
        mp[col].push_back({row, col, root->val});
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<vector<int>>> mp;
        solve(root, mp, 0, 0);
        vector<vector<int>> res;
        for (auto& i : mp) {
            vector<vector<int>> temp = i.second;
            sort(temp.begin(), temp.end(),
                 [&](const vector<int>& a, const vector<int>& b) {
                     if (a[0] == b[0] and a[1] == b[1])
                         return a[2] < b[2];
                     if (a[0] == b[0])
                         return a[1] < b[1];
                     return a[0] < b[0];
                 });
            vector<int> sol;
            for (auto& vec : temp)
                sol.push_back(vec[2]);
            res.push_back(sol);
        }
        return res;
    }
};
