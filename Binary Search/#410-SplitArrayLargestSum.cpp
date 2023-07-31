// M1
// Using Binary Search
// Faster than 100% (-ms)

class Solution
{
public:
    int solve(vector<int> &nums, int target)
    {
        int k = 1, sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (sum + nums[i] <= target)
                sum += nums[i];
            else
            {
                k++;
                sum = nums[i];
            }
        }
        return k;
    }
    int splitArray(vector<int> &nums, int k)
    {
        if (k > nums.size())
            return -1;
        int maxi = *max_element(nums.begin(), nums.end());
        int tsum = accumulate(nums.begin(), nums.end(), 0);
        int low = maxi, high = tsum;
        while (low < high)
        {
            int mid = (low + high) / 2;
            int k1 = solve(nums, mid);
            if (k1 > k)
            {
                low = mid + 1;
            }
            else
                high = mid;
        }
        return high;
    }
};