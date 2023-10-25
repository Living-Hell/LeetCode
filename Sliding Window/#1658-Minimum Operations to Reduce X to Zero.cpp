// M1
// Using sliding window
// Faster than 66.49% (124ms)

class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int tsum = 0, n = nums.size();
        for (int i : nums)
            tsum += i;
        if (tsum < x)
            return -1;
        if (tsum == x)
            return n;
        tsum -= x;
        int i = 0, j = 0, currSum = 0, ans = INT_MAX;
        while (j < n)
        {
            currSum += nums[j];
            while (currSum > tsum)
                currSum -= nums[i++];
            if (currSum == tsum)
            {
                ans = min(ans, n - j + i - 1);
            }
            j++;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};