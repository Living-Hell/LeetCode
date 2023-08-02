// M2
// Using Sliding Window
// Faster than 98.83% (27 ms)

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size(), ind1 = 0, ind2 = 0, sum = 0, ans = INT_MAX;
        while (ind1 < n)
        {
            while (ind1 < n and sum < target)
                sum += nums[ind1++];
            if (sum >= target)
            {
                while (sum >= target)
                {
                    sum -= nums[ind2++];
                    ans = min(ans, ind1 - ind2 + 1);
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};