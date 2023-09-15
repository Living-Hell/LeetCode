// M1
// Using BFS
// Faster than 98.59% (7ms)

class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    grid[i][j] = 0;
                    int count = 1;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (!q.empty())
                    {
                        auto top = q.front();
                        q.pop();
                        int x = top.first, y = top.second;
                        for (auto p : dir)
                        {
                            int i = p.first + x, j = p.second + y;
                            if (i >= 0 and i < m and j >= 0 and j < n and grid[i][j])
                            {
                                count++;
                                grid[i][j] = 0;
                                q.push({i, j});
                            }
                        }
                    }
                    ans = max(ans, count);
                }
            }
        }
        return ans;
    }
};
