// M1
// Using slide window
// Faster than 21.68% (68ms)

class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        if (k == 0)
            return 0;

        long left = 0, right = 0, n = nums.size(), res = 0, curr = 1;

        while (right < n)
        {
            curr *= nums[right];
            if (curr >= k)
            {
                while (curr >= k and left <= right)
                {
                    curr /= nums[left++];
                }
            }
            res += right - left + 1;
            right++;
        }

        return res;
    }
};