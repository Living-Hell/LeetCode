// M1
// Using Dp
// Faster than 100% (0ms)

class Solution
{
public:
    int countOrders(int n)
    {
        long long dp[n + 1];
        int mod = 1e9 + 7;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
            dp[i] = (dp[i - 1] * (2 * i) * ((2 * i) - 1) / 2) % mod;
        return (int)(dp[n] % mod);
    }
};