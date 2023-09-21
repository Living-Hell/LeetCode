// M1
// Using backtracking and dp
// Faster than 86.93% (8ms)

class Solution
{
public:
    int dp[2002][21];
    int solve(vector<int> &nums, int target, int curr, int i)
    {
        if (i == nums.size())
        {
            if (curr == target)
                return 1;
            else
                return 0;
        }
        if (dp[curr + 1000][i] != -1)
            return dp[curr + 1000][i];
        int ans = 0;
        ans += solve(nums, target, curr + nums[i], i + 1);
        ans += solve(nums, target, curr - nums[i], i + 1);
        return dp[curr + 1000][i] = ans;
    }
    int findTargetSumWays(vector<int> &nums, int target)
    {
        memset(dp, -1, sizeof(dp));
        return solve(nums, target, 0, 0);
    }
};