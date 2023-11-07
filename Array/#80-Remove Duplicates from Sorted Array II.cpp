// M1
// Using 2 pointers
// Faster than 100% (0ms)

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int ind = 2, n = nums.size();
        if (n < 3)
            return n;
        for (int i = 2; i < n; i++)
        {
            if (nums[i] != nums[ind - 2])
                nums[ind++] = nums[i];
        }
        return ind;
    }
};