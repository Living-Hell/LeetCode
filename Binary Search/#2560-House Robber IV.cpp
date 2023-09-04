// M1
// Using Binary Search
// Faster than 80.51% (120 ms)

class Solution
{
public:
    bool solve(vector<int> nums, int k, int cap)
    {
        int i = 0;
        while (i < nums.size())
        {
            if (nums[i] <= cap)
                k--, i += 2;
            else
                i++;
            if (k == 0)
                return 1;
        }
        return k == 0;
    }
    int minCapability(vector<int> &nums, int k)
    {
        int high = *max_element(nums.begin(), nums.end());
        int low = *min_element(nums.begin(), nums.end());
        while (low < high)
        {
            int mid = (low + high) / 2;
            bool poss = solve(nums, k, mid);
            if (poss)
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};