// M1
// Using cycle sort
// Faster than 89.1% (48ms)

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size(), curr_ind;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0 and nums[i] <= n)
            {
                curr_ind = nums[i] - 1;
                while (nums[i] > 0 and nums[i] <= n and nums[i] != nums[curr_ind])
                {
                    swap(nums[i], nums[curr_ind]);
                    curr_ind = nums[i] - 1;
                }
            }
        }
        for (int i = 0; i < n; i++)
            if (nums[i] != i + 1)
                return i + 1;
        return n + 1;
    }
};