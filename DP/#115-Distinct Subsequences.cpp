// M1
// Using dp
// Faster than 95.34% (14ms)

class Solution
{
public:
    int dp[1001][1001];
    int solve(string &s, string &t, int i, int j)
    {
        if (i == s.size())
            return j == t.size();

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;

        if (s[i] == t[j])
            ans += solve(s, t, i + 1, j + 1);
        ans += solve(s, t, i + 1, j);

        return dp[i][j] = ans;
    }
    int numDistinct(string &s, string &t)
    {
        memset(dp, -1, sizeof(dp));
        return solve(s, t, 0, 0);
    }
};