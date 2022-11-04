//M1
//Recursion & Breadth First Search
//Faster Than 56% (22ms)

class Solution {
public:    
    vector<int> largestValues(TreeNode* root) {
                
        if(!root) return {};
        
        vector<int> ans;
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(!q.empty()){
            
            int n = q.size();
            int maxelm = INT_MIN;
            
            for(int i=0; i<n; i++){
                
                TreeNode* top = q.front();
                q.pop();
                maxelm = max(maxelm, top->val);
                if(top->left) q.push(top->left);
                if(top->right) q.push(top->right);
                
            }
            
            ans.push_back(maxelm);
        }
        
        return ans;
        
    }
};