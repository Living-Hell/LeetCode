// M1
// Using Topological Sort
// Faster than 46.96% (154 ms)

class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int n = graph.size();
        int indegree[n];
        vector<int> adj[n];
        memset(indegree, 0, sizeof(indegree));
        for (int i = 0; i < n; i++)
        {
            for (const int &x : graph[i])
                adj[x].push_back(i), indegree[i]++;
        }
        vector<int> ans;
        queue<int> q;
        for (int i = 0; i < n; i++)
            if (indegree[i] == 0)
                q.push(i);

        while (!q.empty())
        {
            int top = q.front();
            q.pop();
            ans.push_back(top);
            for (const int &i : adj[top])
            {
                indegree[i]--;
                if (indegree[i] == 0)
                    q.push(i);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};