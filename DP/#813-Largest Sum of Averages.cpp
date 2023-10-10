// M1
// Using recursion and memoization
// Faster than 55.02% (15 ms)

class Solution
{
public:
    vector<vector<double>> dp;
    double solve(vector<int> &nums, int k, int ind)
    {
        if (ind == nums.size())
            return 0;
        if (k == 0)
            return INT_MIN;

        if (dp[k][ind] != -1.0)
            return dp[k][ind];

        double ans = 0.0, sum = 0.0;
        for (int i = ind; i < nums.size(); i++)
        {
            sum += nums[i];
            double avg = sum / (i - ind + 1);
            ans = max(ans, avg + solve(nums, k - 1, i + 1));
        }

        return dp[k][ind] = ans;
    }
    double largestSumOfAverages(vector<int> &nums, int k)
    {
        int n = nums.size();
        dp.resize(k + 1, vector<double>(n + 1, -1.0));
        double ans = solve(nums, k, 0);
        return ans;
    }
};