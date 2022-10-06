//M1 
//Recursion & Depth First Search
//Faster Than 58% (19ms)

class Solution {
public:
    void solve(TreeNode* root, vector<vector<int>> &ans, vector<int> &temp, int currsum, int target){
        
        if(!root) return;
        
        if(currsum == target && !root->left && !root->right){
            ans.push_back(temp);
            return;
        }
        
        if(root->left){
            temp.push_back(root->left->val);
            solve(root->left, ans, temp, currsum+root->left->val, target);
            temp.pop_back();
        }
        
        if(root->right){
            temp.push_back(root->right->val);
            solve(root->right, ans, temp, currsum+root->right->val, target);
            temp.pop_back();    
        }
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        if(!root) return {};
        
        vector<vector<int>> ans;
        vector<int> temp;
        temp.push_back(root->val);
        solve(root, ans, temp, root->val, targetSum);
        
        return ans;
        
    }
};