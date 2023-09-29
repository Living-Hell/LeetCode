// M1
// Using for loops
// Faster than 100% (0ms)

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (int i : nums)
            mp[i]++;
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n - 2; i++)
        {
            int temp = nums[i + 1] - nums[i];
            for (int j = i + 2; j < n; j++)
            {
                if (nums[j] - nums[j - 1] == temp)
                    ans++;
                else
                    break;
            }
        }
        return ans;
    }
};