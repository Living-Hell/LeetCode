// M1
// USing binary search
// Faster than 100% (111ms)

class Solution
{
public:
    int minimizeMax(vector<int> &nums, int p)
    {
        if (p == 0)
            return 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int low = 0, high = nums[n - 1] - nums[0];
        while (low < high)
        {
            int mid = (low + high) / 2, diff, count = 0;
            for (int i = 1; i < n; i++)
            {
                diff = nums[i] - nums[i - 1];
                if (diff <= mid)
                {
                    count++;
                    i++;
                }
            }
            if (count >= p)
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};