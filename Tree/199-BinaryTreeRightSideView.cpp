//M1
//Level Order Traversal Using Queue
//Faster than 6% (16ms)

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        
        if(!root) return {};
        
        vector<vector<int>> res;
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
            
            res.push_back(temp);
        }
        
        vector<int> ans;
        
        for(int i=0; i<res.size(); i++){
            ans.push_back(res[i][res[i].size()-1]);
        }
        
        return ans;
        
    }
};

//M2
//DFS using Recursion
//Faster than 69.34% (4ms) (Memory usage better than 99.94%)

class Solution {
public:
    vector<int> res;
    
    void helper(TreeNode* root, int lvl){
        
        if(!root) return;
        
        if(res.size() == lvl){
            res.push_back(root->val);
        }
        
        helper(root->right, lvl+1);
        helper(root->left, lvl+1);
        
    }
    
    vector<int> rightSideView(TreeNode* root) {
        
        if(!root) return{};
        
        helper(root, 0);
        
        return res;
        
    }
};