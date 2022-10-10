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