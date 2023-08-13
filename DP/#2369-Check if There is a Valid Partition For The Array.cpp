// M1
// Using DP and memoization
// Faster than 86.15% (132ms)

class Solution
{
public:
    bool helper(vector<int> &nums, int i, int n, vector<int> &dp)
    {
        if (i >= n)
            return 1;
        if (dp[i] != -1)
            return dp[i];
        if (i < n - 1 and nums[i] == nums[i + 1])
        {
            dp[i] = helper(nums, i + 2, n, dp);
            if (dp[i])
                return 1;
            if (i < n - 2 and nums[i] == nums[i + 2])
                dp[i] = helper(nums, i + 3, n, dp);
            if (dp[i])
                return 1;
        }
        if (i < n - 2 and nums[i + 2] - nums[i + 1] == 1 and nums[i + 1] - nums[i] == 1)
        {
            dp[i] = helper(nums, i + 3, n, dp);
            if (dp[i])
                return 1;
        }
        dp[i] = 0;
        return 0;
    }
    bool validPartition(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        return helper(nums, 0, n, dp);
    }
};