// M1
// Using two pointers and sorting
// Faster than 69.59% (3ms)

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int n = nums.size();
        int ind = -1, rep = INT_MAX;
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (nums[j] > nums[i])
                {
                    if (rep > nums[j])
                    {
                        rep = nums[j];
                        ind = j;
                    }
                }
            }
            if (ind != -1)
            {
                swap(nums[i], nums[ind]);
                sort(nums.begin() + i + 1, nums.end());
                return;
            }
        }
        sort(nums.begin(), nums.end());
    }
};
