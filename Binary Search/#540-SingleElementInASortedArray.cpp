// M1
// Using Binary Search and the concept that: Elements with freq 2 will have 1st element at even index on left of req value and at odd index at the right.
// Faster than 99.4% (13 ms)

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int low = 0, high = n;
        int ans = -1;
        while (low < high)
        {
            int mid = (low + high) / 2;
            if (mid + 1 < n and nums[mid] == nums[mid + 1])
            {
                if (mid % 2)
                    high = mid;
                else
                    low = mid + 1;
            }
            else if (mid - 1 >= 0 and nums[mid] == nums[mid - 1])
            {
                if ((mid - 1) % 2)
                    high = mid;
                else
                    low = mid + 1;
            }
            else
            {
                ans = nums[mid];
                break;
            }
        }
        return ans;
    }
};