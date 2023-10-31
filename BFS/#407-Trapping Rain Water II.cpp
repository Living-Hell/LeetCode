// M1
// Using BFS and Priority Queue
// Faster than 79.23% (55 ms)

class Solution
{
public:
    int trapRainWater(vector<vector<int>> &hMap)
    {
        int n = hMap.size(), m = hMap[0].size();
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<bool>> vis(n, vector<bool>(m, 0));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            pq.push({hMap[i][0], {i, 0}});
            vis[i][0] = 1;
            pq.push({hMap[i][m - 1], {i, m - 1}});
            vis[i][m - 1] = 1;
        }

        for (int j = 0; j < m; j++)
        {
            pq.push({hMap[0][j], {0, j}});
            vis[0][j] = 1;
            pq.push({hMap[n - 1][j], {n - 1, j}});
            vis[n - 1][j] = 1;
        }

        int minh = 0;
        while (!pq.empty())
        {
            auto top = pq.top();
            int ht = top.first, x = top.second.first, y = top.second.second;
            minh = max(minh, ht);
            pq.pop();
            for (auto p : dir)
            {
                int i = x + p.first, j = y + p.second;
                if (i >= 0 and i < n and j >= 0 and j < m and !vis[i][j])
                {
                    pq.push({hMap[i][j], {i, j}});
                    vis[i][j] = 1;
                    if (hMap[i][j] < minh)
                    {
                        ans += minh - hMap[i][j];
                    }
                }
            }
        }

        return ans;
    }
};