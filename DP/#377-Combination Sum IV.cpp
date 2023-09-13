// M1
// Using DP
// Faster than 53.65% (2ms)

class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        unsigned long long dp[target + 1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 0; i <= target; i++)
        {
            if (dp[i] > 0)
            {
                for (const int &num : nums)
                {
                    if (i + num <= target)
                    {
                        dp[i + num] += dp[i];
                    }
                }
            }
        }
        return dp[target];
    }
};