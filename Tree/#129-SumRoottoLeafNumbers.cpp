//M1
//Recursion & DFS
//Faster than 100% (0ms)

class Solution {
public:
    int ans=0;
    
    void solve(TreeNode* root, int temp){
        
        if(!root) return;
        
        if(!root->left && !root->right){
            temp = temp*10 + root->val;
            ans+= temp;
            return;
        }
        
        solve(root->left, temp*10 + root->val);
        solve(root->right, temp*10 + root->val);
    }
    
    int sumNumbers(TreeNode* root) {
        solve(root,0);
        return ans;
    }
};