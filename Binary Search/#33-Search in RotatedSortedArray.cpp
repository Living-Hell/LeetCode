//M1
//Using binary search
//Faster than 100% (0ms)

class Solution
{
public:
    int bsearch(vector<int> &nums, int target, int low, int high)
    {
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] > target)
                high = mid - 1;
            else if (nums[mid] < target)
                low = mid + 1;
            else
                return mid;
        }
        return -1;
    }
    int search(vector<int> &nums, int target)
    {
        int ind = -1;
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            if (nums[i] < nums[i - 1])
            {
                ind = i;
                break;
            }
        }
        if (ind == -1)
        {
            return bsearch(nums, target, 0, n - 1);
        }
        else
        {
            int a = bsearch(nums, target, 0, ind - 1);
            if (a != -1)
                return a;
            a = bsearch(nums, target, ind, n - 1);
            return a;
        }
    }
};