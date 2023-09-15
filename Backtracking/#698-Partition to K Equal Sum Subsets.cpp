// M1
// Using Backtracking
// Faster than 78.71% (39ms)

class Solution
{
public:
    unordered_map<int, bool> dp;
    bool solve(vector<int> &nums, int k, int tsum, int sum, int &mask, int ind)
    {
        if (k == 1)
            return 1;
        if (sum == tsum)
        {
            return dp[mask] = solve(nums, k - 1, tsum, 0, mask, 0);
        }

        if (dp.contains(mask))
            return dp[mask];

        for (int i = ind; i < nums.size(); i++)
        {
            if (((mask >> i) & 1) or (sum + nums[i] > tsum))
                continue;
            mask |= (1 << i);
            if (solve(nums, k, tsum, sum + nums[i], mask, i + 1))
                return 1;
            mask ^= (1 << i);
        }
        return 0;
    }
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        int tsum = accumulate(nums.begin(), nums.end(), 0);
        int maxi = *max_element(nums.begin(), nums.end());
        if (tsum % k != 0 or tsum / k < maxi)
            return 0;
        int mask = 0;
        return solve(nums, k, tsum / k, 0, mask, 0);
    }
};