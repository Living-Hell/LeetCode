// M1
// Using recursion and dp
// Faster than 85.95% (4ms)

class Solution
{
public:
    int dp[51][51][51];
    int mod = 1e9 + 7;
    int solve(int m, int n, int moves, int x, int y)
    {
        if (moves < 0)
            return 0;
        if (x < 0 or y < 0 or x >= m or y >= n)
            return 1;
        if (dp[x][y][moves] != -1)
            return dp[x][y][moves];
        long long ans = 0;
        ans += solve(m, n, moves - 1, x, y - 1);
        ans += solve(m, n, moves - 1, x, y + 1);
        ans += solve(m, n, moves - 1, x - 1, y);
        ans += solve(m, n, moves - 1, x + 1, y);
        ans %= mod;
        return dp[x][y][moves] = ans;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn)
    {
        memset(dp, -1, sizeof(dp));
        return solve(m, n, maxMove, startRow, startColumn);
    }
};