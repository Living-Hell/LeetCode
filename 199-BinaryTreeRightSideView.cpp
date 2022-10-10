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