//M1
//Using topological sort to find the order of the row and col elements. The projections of elements along the row and col are topologically sorted.
//Faster than 41.53% (102ms)

class Solution {
public:
    vector<int> validOrder(int k, vector<vector<int>> &v){
        int n = v.size();
        vector<int> indegree(k+1,0), order;
        vector<vector<int>> adj(k+1);

        for(int i=0; i<n; i++){
            int a = v[i][0], b = v[i][1];
            indegree[b]++;
            adj[a].push_back(b);
        }

        queue<int> q;
        for(int i=1; i<=k; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int front = q.front();
            q.pop();
            order.push_back(front);
            for(int i:adj[front]){
                indegree[i]--;
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
        }
        return order;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> rowOrder = validOrder(k,rowConditions);
        vector<int> colOrder = validOrder(k,colConditions);

        if(rowOrder.size() != k or colOrder.size() != k) return {};

        vector<vector<int>> res(k,vector<int>(k,0));

        for(int i=0; i<k; i++){
            for(int j=0; j<k; j++){
                if(rowOrder[i] == colOrder[j]){
                    res[i][j] = rowOrder[i];
                }
            }
        }

        return res;
    }
};
