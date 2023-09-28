// M1
// Using DP
// Faster than 67.22% (107 ms)

class Solution
{
public:
    int maxRotateFunction(vector<int> &nums)
    {
        int n = nums.size();
        int tsum = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += i * nums[i];
            tsum += nums[i];
        }
        int temp = ans;
        for (int i = 1; i < n; i++)
        {
            int temp1 = temp - tsum + nums[i - 1] * n;
            ans = max(ans, temp1);
            temp = temp1;
        }
        return ans;
    }
};