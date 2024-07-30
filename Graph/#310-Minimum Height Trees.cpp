//M1
//Using Topological Sort and BFS
//Faster than 80.33% (101ms)

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        vector<int> indegree(n,0),res;
        vector<vector<int>> adjList(n);

        for(auto &e : edges){
            int a = e[0], b = e[1];
            indegree[a]++, indegree[b]++;
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }

        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i] == 1){
                q.push(i);
                indegree[i]--;
            }
        }

        while(q.size()){
            int sz = q.size();
            res.clear();
            for(int i=0; i<sz; i++){
                int top = q.front();
                q.pop();
                res.push_back(top);
                for(int i : adjList[top]){
                    indegree[i]--;
                    if(indegree[i] == 1)
                        q.push(i);
                }
            }
        }
        return res;
    }
};
