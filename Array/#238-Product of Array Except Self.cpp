// M1
// Using Simulation
// Faster than 53.64% (21ms)

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int prod = 1, count0 = 0;
        int n = nums.size();
        for (int i : nums)
        {
            if (i == 0)
                count0++;
            else
                prod *= i;
        }
        vector<int> ans(n, 0);
        if (count0 > 1)
            return ans;
        for (int i = 0; i < n; i++)
        {
            if (count0 == 1 and nums[i] == 0)
            {
                ans[i] = prod;
                return ans;
            }
            else if (count0 == 0)
                ans[i] = prod / nums[i];
        }
        return ans;
    }
};