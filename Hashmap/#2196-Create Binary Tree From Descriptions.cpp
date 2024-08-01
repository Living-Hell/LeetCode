//M1
//Using Hashmaps
//Faster than 50.98% (717ms)

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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_map<int, bool> isChild;
        int n = descriptions.size();

        for (auto& i : descriptions) {
            int par = i[0], child = i[1], isLeft = i[2];
            isChild[child] = 1;
            if (mp.find(par) == mp.end()) {
                TreeNode* root = new TreeNode(par);
                mp[par] = root;
                mp[par] = root;
            }
            if (mp.find(child) == mp.end()) {
                TreeNode* childNode = new TreeNode(child);
                mp[child] = childNode;
            }
            if (isLeft)
                mp[par]->left = mp[child];
            else
                mp[par]->right = mp[child];
        }
        for (auto& i : descriptions) {
            if (isChild[i[0]] == 0)
                return mp[i[0]];
        }
        return NULL;
    }
};
