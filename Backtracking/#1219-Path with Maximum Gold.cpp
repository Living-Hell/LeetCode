// M1
// Using backtracking
// Faster than 11.14% (366ms)

class Solution
{
public:
    int solve(vector<vector<int>> &grid, int i, int j, int m, int n, vector<vector<bool>> &vis)
    {
        if (i < 0 or i >= m or j < 0 or j >= n or vis[i][j] or !grid[i][j])
            return 0;
        vis[i][j] = 1;
        int ans = 0;
        ans = grid[i][j] + max({solve(grid, i + 1, j, m, n, vis), solve(grid, i - 1, j, m, n, vis),
                                solve(grid, i, j + 1, m, n, vis), solve(grid, i, j - 1, m, n, vis)});
        vis[i][j] = 0;
        return ans;
    }
    int getMaximumGold(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    vector<vector<bool>> vis(m, vector<bool>(n, 0));
                    ans = max(ans, solve(grid, i, j, m, n, vis));
                }
            }
        }
        return ans;
    }
};