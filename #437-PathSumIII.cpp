//M1
//Recursion and DFS
//Faster than 52.72% (41ms)

class Solution {
public:
    int ans=0;
    
    void solve(TreeNode* root, long long currsum, int target){
        
        if(!root) return;
        
        currsum+= root->val;
        
        if(currsum == target){
            ans++;
        }
        
        if(root->left) solve(root->left, currsum, target);
        if(root->right) solve(root->right, currsum, target);
        
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        
        if(!root) return 0;
        
        solve(root, 0, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        
        return ans;
        
    }
};