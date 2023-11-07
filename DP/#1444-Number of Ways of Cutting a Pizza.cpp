// M1
// Using Dp
// Faster than 72.39% (18ms)

class Solution
{
public:
    int dp[52][52][11];
    int mod = 1e9 + 7;
    int solve(vector<string> &pizza, int n, int m, int k, int row, int col, vector<vector<int>> &apples)
    {
        if (apples[row][col] == 0)
            return 0;
        if (k == 0)
            return 1;

        if (dp[row][col][k] != -1)
            return dp[row][col][k];

        int ans = 0;
        for (int i = row + 1; i < n; i++)
        {
            if (apples[row][col] - apples[i][col] > 0)
            {
                ans = (ans + solve(pizza, n, m, k - 1, i, col, apples)) % mod;
            }
        }
        for (int i = col + 1; i < m; i++)
        {
            if (apples[row][col] - apples[row][i] > 0)
            {
                ans = (ans + solve(pizza, n, m, k - 1, row, i, apples)) % mod;
            }
        }
        return dp[row][col][k] = ans;
    }
    int ways(vector<string> &pizza, int k)
    {
        int n = pizza.size(), m = pizza[0].size();
        vector<vector<int>> apples(n, vector<int>(m));
        apples[n - 1][m - 1] = pizza[n - 1][m - 1] == 'A';

        for (int i = n - 2; i >= 0; i--)
        {
            apples[i][m - 1] = (pizza[i][m - 1] == 'A') + apples[i + 1][m - 1];
        }

        for (int i = m - 2; i >= 0; i--)
        {
            apples[n - 1][i] = (pizza[n - 1][i] == 'A') + apples[n - 1][i + 1];
        }

        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = m - 2; j >= 0; j--)
            {
                apples[i][j] = -apples[i + 1][j + 1] + (pizza[i][j] == 'A') + apples[i + 1][j] + apples[i][j + 1];
            }
        }

        memset(dp, -1, sizeof(dp));
        return solve(pizza, n, m, k - 1, 0, 0, apples);
    }
};