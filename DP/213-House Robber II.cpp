// M1
// Using Dp (vector)
// Faster than 28.4% (4ms)
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        int a = nums[0], b = max(nums[0], nums[1]), c = b;
        if (n == 2)
            return b;
        for (int i = 2; i < n - 1; i++)
        {
            c = max(a + nums[i], b);
            a = b;
            b = c;
        }
        int temp = c;
        a = nums[1], b = max(nums[1], nums[2]), c = b;
        for (int i = 3; i < n; i++)
        {
            c = max(a + nums[i], b);
            a = b;
            b = c;
        }
        return max(temp, c);
    }
};

// M2
// Using 2 variables (similar to dp)
// Faster than 100% (.ms)
class Solution
{
public:
    int robber(vector<int> &nums, int st, int end)
    {
        int a = 0, b = 0;
        for (int i = st; i < end; i++)
        {
            int c = max(b, a + nums[i]);
            a = b;
            b = c;
        }
        return b;
    }
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        return max(robber(nums, 0, n - 1), robber(nums, 1, n));
    }
};