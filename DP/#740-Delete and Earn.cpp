// M1
// Using Dp (similar to house robber problem)
// Faster than 57.43% (12 ms)

class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        vector<int> val(10001, 0), dp(10001, 0);
        for (const int &i : nums)
            val[i] += i;
        dp[0] = 0;
        dp[1] = val[1];
        for (int i = 2; i <= 10000; i++)
            dp[i] = max(dp[i - 2] + val[i], dp[i - 1]);
        return dp[10000];
    }
};