// M1
// Using Binary Search
// Faster than 90.15% (35 ms)

class Solution
{
public:
    int helper(vector<int> &nums, int len)
    {
        int tsum = INT_MIN;
        for (int i = 0; i + len - 1 < nums.size(); i++)
        {
            int sum = i == 0 ? nums[i + len - 1] : nums[i + len - 1] - nums[i - 1];
            tsum = max(tsum, sum);
        }
        return tsum;
    }
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        if (total < target)
            return 0;
        int low = 1, high = n;
        for (int i = 1; i < n; i++)
            nums[i] += nums[i - 1];
        while (low < high)
        {
            int mid = (low + high) / 2;
            int sum = helper(nums, mid);
            if (sum < target)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }
};