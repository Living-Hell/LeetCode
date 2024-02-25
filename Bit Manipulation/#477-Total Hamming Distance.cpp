// M1
// Using bit manipulation, counting set bits
// Faster than 70.31% (34 ms)

class Solution
{
public:
    int totalHammingDistance(vector<int> &nums)
    {
        int sum = 0, n = nums.size();
        int a[32] = {0};

        for (int i = 0; i < 32; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (nums[j] & (1 << i))
                {
                    a[i]++;
                }
            }
        }
        for (int i = 0; i < 32; i++)
            sum += a[i] * (n - a[i]);

        return sum;
    }
};