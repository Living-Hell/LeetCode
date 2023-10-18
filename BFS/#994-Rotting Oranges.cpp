// M1
// Using BFS
// Faster than 63.96% (4ms)

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({i, j});
                }
            }
        }
        int min = 0;
        while (q.size())
        {
            int sz = q.size();
            for (int it = 0; it < sz; it++)
            {
                auto [x, y] = q.front();
                q.pop();
                for (auto p : dir)
                {
                    int i = x + p.first, j = y + p.second;
                    if (i >= 0 and i < m and j >= 0 and j < n and grid[i][j] == 1)
                    {
                        grid[i][j] = 2;
                        q.push({i, j});
                    }
                }
            }
            min++;
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    return -1;
            }
        }
        return min == 0 ? 0 : min - 1;
    }
};