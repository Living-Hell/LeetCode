// M1
// Using adjacency list
// Faster than 66.29% (86ms)

class Solution
{
public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads)
    {
        vector<vector<int>> adj(n, vector<int>());
        for (auto i : roads)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int network = adj[i].size() + adj[j].size();
                if (count(adj[i].begin(), adj[i].end(), j))
                    network--;
                ans = max(ans, network);
            }
        }
        return ans;
    }
};