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

// M2
// Using prefix and suffix product
// Faster than 84.97% (15 ms)

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size(), countz = 0, tprod = 1;
        for (int i : nums)
        {
            if (i == 0)
                countz++;
            else
                tprod *= i;
        }
        vector<int> ans(n);
        if (countz == 1)
        {
            for (int i = 0; i < n; i++)
            {
                if (nums[i] == 0)
                    ans[i] = tprod;
            }
        }
        else if (countz == 0)
        {
            ans[n - 1] = 1;
            for (int i = n - 2; i >= 0; i--)
            {
                ans[i] = ans[i + 1] * nums[i + 1];
            }
            int pref = 1;
            for (int i = 1; i < n; i++)
            {
                pref *= nums[i - 1];
                ans[i] *= pref;
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
                ans[i] = 0;
        }
        return ans;
    }
};