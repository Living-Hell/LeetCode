// M1
// Using Digit DP
// Faster than 24.95% (25ms)

class Solution
{
public:
    int dp[10][2][1 << 10];
    int solve(string num, int pos, int tight, int mask)
    {
        if (pos == num.size())
        {
            return 1;
        }
        if (dp[pos][tight][mask] != -1)
            return dp[pos][tight][mask];
        int ans = 0;
        int ub = tight ? num[pos] - '0' : 9;
        for (int i = 0; i <= ub; i++)
        {
            if ((1 << i) & mask)
                continue;
            if (i == 0)
            {
                if (mask)
                    ans += solve(num, pos + 1, tight & (i == ub), mask | 1);
                else
                    ans += solve(num, pos + 1, tight & (i == ub), mask);
            }
            else
                ans += solve(num, pos + 1, tight & (i == ub), mask | (1 << i));
        }
        return dp[pos][tight][mask] = ans;
    }
    int countSpecialNumbers(int n)
    {
        memset(dp, -1, sizeof(dp));
        string num = to_string(n);
        return solve(num, 0, 1, 0) - 1;
    }
};