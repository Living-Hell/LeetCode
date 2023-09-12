// M1
// Using Binary Search
// Faster than 100% (0ms)

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        int start = 0, end = n - 1;
        while (start < end)
        {
            int mid = (start + end) / 2;
            if (nums[mid] >= nums[start] and nums[mid] >= nums[end])
                start = mid + 1;
            else
                end = mid;
        }
        return nums[start];
    }
};