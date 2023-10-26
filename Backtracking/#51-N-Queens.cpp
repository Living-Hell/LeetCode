// M1
// Using backtracking
// Faster than 86.82% (3ms)

class Solution
{
public:
    bool isSafe(vector<string> &grid, int i, int j, int n)
    {
        for (int k = 0; k < n; k++)
        {
            if (grid[k][j] == 'Q')
                return 0;
            if (grid[i][k] == 'Q')
                return 0;
            if (i + j - k >= 0 and i + j - k < n and grid[k][i + j - k] == 'Q')
                return 0;
            if (k + j - i >= 0 and k + j - i < n and grid[k][k + j - i] == 'Q')
                return 0;
        }
        return 1;
    }
    void solve(vector<vector<string>> &ans, vector<string> grid, int n, int i)
    {
        if (i == n)
        {
            ans.push_back(grid);
            return;
        }
        for (int j = 0; j < n; j++)
        {
            if (isSafe(grid, i, j, n))
            {
                grid[i][j] = 'Q';
                solve(ans, grid, n, i + 1);
                grid[i][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        string row;
        for (int i = 0; i < n; i++)
            row.push_back('.');

        vector<vector<string>> ans;
        vector<string> grid(n, row);

        solve(ans, grid, n, 0);
        return ans;
    }
};
