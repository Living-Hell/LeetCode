//M1
//Using greedy 
//Faster than 44.21% (279ms)

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> adj(n,0);

        for(int i=0; i<roads.size(); i++){
            int a = roads[i][0], b = roads[i][1];
            adj[a]++;
            adj[b]++;
        }

        vector<pair<int,long long>> v;
        for(int i=0; i<n; i++){
            v.push_back({adj[i],i});
        }

        sort(v.begin(),v.end(), greater<pair<int,long long>>());

        vector<long long> imp(n);
        for(int i=0; i<n; i++){
            imp[v[i].second] = n-i;
        }

        long long res = 0;
        for(int i=0; i<roads.size(); i++){
            int a = roads[i][0], b = roads[i][1];
            res += imp[a] + imp[b];
        }
        
        return res;
    }
};
