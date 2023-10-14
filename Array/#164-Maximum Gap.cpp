// M1
// Using bucket sort
// Faster than 84.73% (137ms)

class Solution
{
public:
    // Using Bucket sort
    int maximumGap(vector<int> &nums)
    {
        int n = nums.size();

        if (n < 2)
            return 0;
        if (n == 2)
            return abs(nums[0] - nums[1]);

        vector<int> minBucket(n - 1, INT_MAX);
        vector<int> maxBucket(n - 1, INT_MIN);

        int mine = *min_element(nums.begin(), nums.end());
        int maxe = *max_element(nums.begin(), nums.end());

        int gap = ceil((maxe - mine) / (float)(n - 1));

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == mine or nums[i] == maxe)
                continue;
            int ind = (nums[i] - mine) / gap;
            minBucket[ind] = min(minBucket[ind], nums[i]);
            maxBucket[ind] = max(maxBucket[ind], nums[i]);
        }

        int currMax = mine, ans = gap;
        for (int i = 0; i < n - 1; i++)
        {
            if (minBucket[i] == INT_MAX and maxBucket[i] == INT_MIN)
                continue;
            ans = max(ans, minBucket[i] - currMax);
            currMax = maxBucket[i];
        }
        ans = max(ans, maxe - currMax);

        return ans;
    }
};