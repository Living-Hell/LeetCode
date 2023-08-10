// M1
// Using DP
// Faster than 100% (.ms)
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++)
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        return dp[n - 1];
    }
};

// M2
// Using 2 varaibles (similar 2 dp)
// Faster than 100% (.ms)
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int a = nums[0], b = max(nums[0], nums[1]), c = b;
        for (int i = 2; i < n; i++)
        {
            c = max(a + nums[i], b);
            a = b;
            b = c;
        }
        return c;
    }
};