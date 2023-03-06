//M1
//Using Djikstra Algorithm (BFS Queue)
//Faster than 30ms(63.39%)

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<vector<int>> q;
        q.push({0,src,k+1});

        vector<vector<pair<int,int>>> adj(n,vector<pair<int,int>>());
        for(auto i:flights){
            adj[i[0]].push_back({i[1],i[2]});
        }

        vector<int> dist(n,INT_MAX);
        dist[src] = 0;

        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int node = top[1];
            int curr_cost = top[0];
            int stop_left = top[2];
            
            if(stop_left<0) continue;
            
            for(auto i:adj[node]){
                if(stop_left>0 && dist[i.first] > curr_cost + i.second){
                    dist[i.first] = curr_cost + i.second;
                    q.push({curr_cost+i.second,i.first,stop_left-1});
                }
            }
        }
        if(dist[dst] == INT_MAX) return -1;      
        return dist[dst];  
    }
};