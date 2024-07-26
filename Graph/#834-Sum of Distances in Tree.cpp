//M1
//Using BFS
//Faster than % (ms) [TLE]

class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> res(n,0);
        vector<vector<int>> adj(n);
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        for(int i=0; i<n; i++){
            queue<int> q;
            q.push(i);
            vector<int> vis(n,0);
            vis[i] = 1;
            int counter = 0, ans = 0;
            while(q.size()){
                int sz = q.size();
                counter++;
                while(sz--){
                    int top = q.front(); q.pop();
                    for(int ad : adj[top]){
                        if(!vis[ad]){
                            q.push(ad);
                            vis[ad] = 1;
                            ans += counter;
                        }
                    }
                }
            }
            res[i] = ans;
        }

        return res;

    }
};

//M2
//Using DFS and root shifting technique
//Faster than 95.16% (178ms)
class Solution {
public:
    void dfs(vector<vector<int>> &adj, vector<int> &res, vector<int> &counter, int node, int prevNode = -1){
        for(auto ad : adj[node]){
            if(ad == prevNode) continue;
            dfs(adj,res,counter,ad,node);
            counter[node] += counter[ad];
            res[node] += res[ad] + counter[ad];
        }
        counter[node] += 1;
    }
    void dfs2(vector<vector<int>> &adj, vector<int> &res, vector<int> &counter, int node, int n, int prevNode = -1){
        for(auto ad : adj[node]){
            if(ad == prevNode) continue;
            res[ad] = res[node] - counter[ad] + n - counter[ad];
            dfs2(adj,res,counter,ad,n, node);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> res(n,0), counter(n,0);
        vector<vector<int>> adj(n);
        for(auto &e:edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(adj,res,counter,0);
        dfs2(adj,res,counter,0,n);

        return res;

    }
};
