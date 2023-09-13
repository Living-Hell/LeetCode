// M1
// Using Recursion and memoization
// Faster than 42.45% (44 ms)

class Solution
{
public:
    int dp[1002];
    void solve(vector<int> &nums, vector<int> &temp, vector<int> &ans, int ind)
    {
        if (ind == nums.size())
        {
            if (temp.size() > ans.size())
                ans = temp;
            return;
        }
        if (temp.size() == 0)
        {
            temp.push_back(nums[ind]);
            solve(nums, temp, ans, ind + 1);
            temp.pop_back();
        }

        else if (dp[ind] < (int)temp.size() and nums[ind] % temp.back() == 0)
        {
            dp[ind] = temp.size();
            temp.push_back(nums[ind]);
            solve(nums, temp, ans, ind + 1);
            temp.pop_back();
        }
        solve(nums, temp, ans, ind + 1);
    }
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        memset(dp, -1, sizeof(dp));
        sort(nums.begin(), nums.end());
        vector<int> temp, ans;
        solve(nums, temp, ans, 0);
        return ans;
    }
};