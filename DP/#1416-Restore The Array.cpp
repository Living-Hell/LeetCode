// M1
// Using DP
// Faster than 27.36% (117ms)

class Solution
{
public:
    int numberOfArrays(string s, int k)
    {
        int n = s.size(), m = to_string(k).size(), mod = 1e9 + 7;
        if (n == 1)
            return s[0] - '0' <= k;

        long long int dp[n];
        memset(dp, 0, sizeof(dp));

        dp[0] = s[0] - '0' <= k;

        for (int i = 1; i < min(n, m - 1); i++)
        {
            if (s[i] == '0')
                dp[i] = dp[i - 1];
            else
                dp[i] = dp[i - 1] * 2;
        }

        for (int i = m - 1; i < n; i++)
        {
            long long int num = 0;
            for (int j = i; j >= max(0, i - m); j--)
            {
                num = pow(10, i - j) * (s[j] - '0') + num;
                if (num > 0 and num <= k and s[j] != '0')
                    dp[i] = (dp[i] + (j - 1 >= 0 ? dp[j - 1] : 1)) % mod;
            }
        }
        return dp[n - 1];
    }
};