// M1
// Using sorting and greedy approach
// Faster than 36.79% (28 ms)

class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        int n = nums.size(), st = -1, end = n;
        vector<int> v = nums;
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++)
        {
            if (v[i] != nums[i])
            {
                st = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (v[i] != nums[i])
            {
                end = i;
                break;
            }
        }
        return (st == -1 and end == n) ? 0 : end - st + 1;
    }
};

// M1
// Using greedy approach
// Faster than 66.04% (23 ms)
class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        int n = nums.size(), st = -1, end = n;
        int mine = INT_MAX, maxe = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            maxe = max(maxe, nums[i]);
            if (nums[i] != maxe)
            {
                end = i;
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            mine = min(mine, nums[i]);
            if (nums[i] != mine)
            {
                st = i;
            }
        }
        return (st == -1 and end == n) ? 0 : end - st + 1;
    }
};