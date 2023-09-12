// M1
// Using backtracking and DP
// Faster than 100% (0ms)

class Solution
{
public:
    int dp[202][202];
    int dfs(vector<vector<int>> &triangle, int row, int col)
    {
        if (row == triangle.size() or col == triangle[row].size())
            return 0;
        if (dp[row][col] != -1)
            return dp[row][col];
        int curr_sum = triangle[row][col];
        curr_sum += min(dfs(triangle, row + 1, col), dfs(triangle, row + 1, col + 1));
        return dp[row][col] = curr_sum;
    }
    int minimumTotal(vector<vector<int>> &triangle)
    {
        memset(dp, -1, sizeof(dp));
        return dfs(triangle, 0, 0);
    }
};
