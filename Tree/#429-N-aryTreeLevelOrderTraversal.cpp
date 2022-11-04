//M1
//BFS using Queue
//Faster than 61.3% (37ms)

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
       
        if(!root) return {};
       
        vector<vector<int>> ans;
       
        queue<Node*> q;
        q.push(root);
       
        while(!q.empty()){
            int n = q.size();
            vector<int> temp;
           
            for(int i=0; i<n; i++){
               
                Node* top = q.front();
                q.pop();
                temp.push_back(top->val);
               
                for(int j=0; j<top->children.size(); j++)
                    q.push(top->children[j]);
            }
           
            ans.push_back(temp);

        }
       
        return ans;
       
       
    }
};

//M2
//Recursion
// Faster Than 71.26% (32ms)

class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(Node* root, int depth){
        
        if(!root) return;
        
        if(ans.size() == depth){
            ans.push_back({});
        }
        
        ans[depth].push_back(root->val);
        
        for(int i=0; i<root->children.size(); i++)
            solve(root->children[i], depth+1);
        
    }    
    
    vector<vector<int>> levelOrder(Node* root) {
       
        if(!root) return {};
       
        solve(root, 0);
       
        return ans;
       
       
    }
};