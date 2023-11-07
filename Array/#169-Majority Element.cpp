// M1
// Using counting
// Faster than 84.15% (11ms)

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int ans = nums[0], count = 1, n = nums.size();
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == ans)
                count++;
            else
                count--;
            if (count == 0)
            {
                ans = nums[i];
                count++;
            }
        }
        return ans;
    }
};