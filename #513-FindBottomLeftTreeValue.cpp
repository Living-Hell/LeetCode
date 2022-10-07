//M1
//BFS using Queue
//Faster than 85.17% (14ms)

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        
        vector<vector<int>> ans;
        
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
        
        int res = ans[ans.size()-1][0];
        return res;
        
    }
};

//M2
//BFS using Queue
//Faster than 54% (21ms)

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
                
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
                
            root = q.front(); q.pop();
            if(root->right) q.push(root->right);
            if(root->left) q.push(root->left);
                
        }
        
        return root->val;
        
    }
};