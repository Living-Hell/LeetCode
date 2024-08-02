//M1
//Using Djikstra's Algorithm
//Faster than 58.55% (83ms)

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adjList(n);
        vector<int> dist(n,INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

        for(auto &t:times){
            int u = t[0], v = t[1], wt = t[2];
            adjList[u-1].push_back({v-1,wt});
        }

        pq.push({0,k-1});
        dist[k-1] = 0;

        while(!pq.empty()){
            auto [_,node] = pq.top();
            pq.pop();
            for(auto &adj:adjList[node]){
                int u = adj.first, wt = adj.second;
                if(dist[node] + wt < dist[u]){
                    dist[u] = dist[node] + wt;
                    pq.push({dist[u],u});
                }
            }
        }
        int res = 0;
        for(int i=0; i<n; i++){
            if(dist[i] == INT_MAX)
                return -1;
            res = max(res,dist[i]);
        }
        return res;
    }
};
