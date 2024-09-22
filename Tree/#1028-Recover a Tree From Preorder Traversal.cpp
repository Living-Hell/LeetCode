//M1
//Using DFS
//Faster than 92.25% (10ms)

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
    TreeNode* recoverFromPreorder(string s) {
        int n = s.size();
        stack<TreeNode*> st;
        for (int i = 0, lvl, val; i < n;) {
            for (lvl = 0; s[i] == '-'; i++)
                lvl++;
            for (val = 0; i < n and s[i] != '-'; i++)
                val = val * 10 + (s[i] - '0');
            while (st.size() > lvl)
                st.pop();
            TreeNode* node = new TreeNode(val);
            if (!st.empty()) {
                if (!st.top()->left)
                    st.top()->left = node;
                else
                    st.top()->right = node;
            }
            st.push(node);
        }
        while (st.size() > 1)
            st.pop();
        return st.top();
    }
};
