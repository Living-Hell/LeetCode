// M1
// Using DFS
// Faster than 100% (0ms)

class Solution
{
public:
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int solve(vector<vector<int>> &grid, int x, int y, int empty)
    {
        if (grid[x][y] == 2)
            return empty == 0;

        int ans = 0;

        grid[x][y] = -1;

        for (auto p : dir)
        {
            int i = x + p.first, j = y + p.second;
            if (i >= 0 and i < grid.size() and j >= 0 and j < grid[0].size() and grid[i][j] != -1)
            {
                ans += solve(grid, i, j, empty - 1);
            }
        }

        grid[x][y] = 0;

        return ans;
    }
    int uniquePathsIII(vector<vector<int>> &grid)
    {
        pair<int, int> st;
        int n = grid.size(), m = grid[0].size(), empty = 1;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                    st.first = i, st.second = j;
                if (grid[i][j] == 0)
                    empty++;
            }
        }

        return solve(grid, st.first, st.second, empty);
    }
};