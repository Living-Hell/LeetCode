//M1
//Using Recursion
//Faster than 75.56% (4ms)

class Solution {
public:
    int ind = 0; 
    TreeNode* solve(vector<int>& pre, int bound) {
        if(ind>=pre.size() or pre[ind] > bound) return NULL;
        TreeNode* root = new TreeNode(pre[ind++]);
        root->left = solve(pre,root->val);
        root->right = solve(pre,bound);
        return root; 
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return solve(preorder,INT_MAX);
    }
};