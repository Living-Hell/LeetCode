//M1
//Using DP
//Faster than 99.47% (68 ms)

class Solution
{
public:
    int longestArithSeqLength(vector<int> &nums)
    {
        int n = nums.size();
        int dp[n][1002];
        int ans = 0;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int diff = nums[j] - nums[i] + 500;
                dp[j][diff] = dp[i][diff] + 1;
                ans = max(ans, dp[j][diff]);
            }
        }
        return ans + 1;
    }
};