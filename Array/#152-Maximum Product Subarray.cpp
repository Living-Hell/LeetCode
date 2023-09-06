// M1
// using Intuition and observation, prefix and suffix product and dividing the arrat on 0
// Faster than 100% (0ms)

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int ans = *max_element(nums.begin(), nums.end());
        int pref = 1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 0)
            {
                pref = 1;
                continue;
            }
            pref *= nums[i];
            ans = max(ans, pref);
        }
        int suff = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] == 0)
            {
                suff = 1;
                continue;
            }
            suff *= nums[i];
            ans = max(ans, suff);
        }
        return ans;
    }
};

// M2
// Faster than 64.64% (5ms)

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        int ans = INT_MIN;
        int pref = 1, suff = 1;
        for (int i = 0; i < n; i++)
        {
            if (pref == 0)
                pref = 1;
            if (suff == 0)
                suff = 1;
            pref *= nums[i];
            suff *= nums[n - i - 1];
            ans = max(ans, max(pref, suff));
        }
        return ans;
    }
};