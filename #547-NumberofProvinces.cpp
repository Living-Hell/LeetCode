//M1
//DFS using Recursion
//Faster than 31.95% (57ms)

class Solution {
public:
    void dfs(int s, vector<vector<int>> &adj, vector<int> &visited){
        visited[s] = 1;
        for( auto it : adj[s]){
            if(!visited[it]){
                visited[it] = 1;
                dfs(it, adj, visited);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        vector<int> visited(n,0);
        vector<vector<int>> adj(n);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i!=j && isConnected[i][j]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        int count=0;
        
        for(int i=0; i<n; i++){
            if(!visited[i]){
                count++;
                dfs(i,adj,visited);
            }
        }
        
        return count;
        
    }
};