//M1
//Recursion using map
//Faster than 7.39% (15ms)

class Solution {
public:
    void helper(TreeNode* root, int level, map<int, vector<int>> &mp){
        
        if(root == NULL) return;
        
        mp[level].push_back(root->val);
        
        helper(root->left, level+1, mp);
        helper(root->right, level+1, mp);
        
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        map<int,vector<int>> mp;
        vector<vector<int>> ans;
        
        helper(root, 0, mp);
        
        for(auto i:mp)
            ans.push_back(i.second);
        
        return ans;
        
    }
};

//M2
//Recursion
// Faster Than 90% (3ms)

class Solution {
public:
    vector<vector<int>> ans;
    
    void helper(TreeNode* root, int level){
        
        if(root == NULL) return;
        
        if(ans.size() == level)
            ans.push_back(vector<int>());
        
        ans[level].push_back(root->val);
        
        helper(root->left, level+1);
        helper(root->right, level+1);
        
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        helper(root, 0);
        
        return ans;
        
    }
};

//M3
//Breadth First Search using Queue
// Faster Than 100% (0ms)

class Solution {
public:    
    vector<vector<int>> levelOrder(TreeNode* root) {
    
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
        
        return ans;
        
    }
};