// M1
// Sorting
// Faster than 98.8% (11ms)

class Solution
{
public:
    int smallestRangeII(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = nums[n - 1] - nums[0];
        int maxe = nums[n - 1] - k, mine = nums[0] + k, mn, mx;
        for (int i = 0; i < n - 1; i++)
        {
            mx = max(maxe, nums[i] + k);
            mn = min(mine, nums[i + 1] - k);
            ans = min(ans, mx - mn);
        }
        return ans;
    }
};