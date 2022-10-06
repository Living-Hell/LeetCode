//M1
//Recursion
//Faster than 15.27% (14ms)

class Solution {
public:
    void helper(TreeNode* root, int level, vector<vector<int>> &ans){
        
        if(root == NULL) return;
        
        if(ans.size() == level) ans.push_back(vector<int>());
        
        ans[level].push_back(root->val);
        
        helper(root->left, level+1, ans);
        helper(root->right, level+1, ans);
        
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int>> ans;
        
        helper(root, 0, ans);
        
        reverse(ans.begin(), ans.end());
        
        return ans;
        
    }
};

//M2
//Breadth First Search using Queue
// Faster Than 66.26% (6ms)

class Solution {
public:    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int>> ans;
        
        if(!root) return ans;
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(!q.empty()){
            
            int n = q.size();
            vector<int> temp;
            
            for(int i=0; i<n; i++){
                
                TreeNode* top = q.front();
                q.pop();
                temp.push_back(top->val);
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
                
            }
            
            ans.push_back(temp);
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
        
    }
};