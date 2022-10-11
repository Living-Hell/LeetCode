//M1
//BFS using Queue
//Faster than 32.5% (1384ms)

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        
        if(edges.size() == 0) return true;
        
        unordered_map<int, list<int>> adjlist;
        
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
            
            if((u == source && v == destination) || u == destination && v == source)
                return true;
        }
        
        queue<int> q;
        vector<bool> visited (n,0);
        
        q.push(source);
        visited[source] = 1;
        
        while(!q.empty()){
            int top = q.front();
            q.pop();
            
            
            for(auto &node : adjlist[top]){
                if(!visited[node]){
                    visited[node] = 1;
                    q.push(node);
                }
                
                if(node == destination)
                    return true;
            }
        }
        
        return false;
        
    }
};