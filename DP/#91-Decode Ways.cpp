// M1
// Using DP
// Faster than 46.36% (3ms)

class Solution
{
public:
    int numDecodings(string s)
    {
        if (s[0] == '0')
            return 0;
        int n = s.size();
        if (n == 1)
            return 1;

        int dp[n];
        dp[0] = 1;
        dp[1] = s[1] != '0';
        if (s[0] == '1')
            dp[1]++;
        else if (s[0] == '2' and s[1] <= '6')
            dp[1]++;

        for (int i = 2; i < n; i++)
        {
            if (s[i] == '0' and s[i - 1] == '0')
                dp[i] = 0;
            else if (s[i] == '0')
            {
                if (s[i - 1] <= '2')
                    dp[i] = dp[i - 2];
                else
                    dp[i] = 0;
            }
            else if (s[i - 1] == '0')
            {
                dp[i] = dp[i - 1];
            }
            else
            {
                dp[i] = dp[i - 1];
                if ((s[i - 1] == '1') or (s[i - 1] == '2' and s[i] <= '6'))
                    dp[i] += dp[i - 2];
            }
        }
        return dp[n - 1];
    }
};