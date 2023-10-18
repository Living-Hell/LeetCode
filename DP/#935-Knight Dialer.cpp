// M1
// Using BFS + DP
// Faster than 61.44% (123ms)

class Solution
{
public:
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {-1, 0, -1}};
    vector<pair<int, int>> dir = {{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {1, 2}, {-1, 2}, {1, -2}, {-1, -2}};
    int mod = 1000000007;
    int dp[5][4][5001];
    int rows = 4, cols = 3;
    int solve(int n, int x, int y)
    {
        if (n == 0)
            return 1;

        if (dp[x][y][n] != -1)
            return dp[x][y][n];

        int ans = 0;

        for (auto p : dir)
        {
            int i = p.first + x, j = p.second + y;
            if (i >= 0 and i < 4 and j >= 0 and j < 3 and grid[i][j] != -1)
            {
                ans = (ans + solve(n - 1, i, j)) % mod;
            }
        }
        return dp[x][y][n] = ans % mod;
    }
    int knightDialer(int n)
    {
        int ans = 0;
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (grid[i][j] != -1)
                {
                    ans = (ans + solve(n - 1, i, j)) % mod;
                }
            }
        }
        return ans;
    }
};