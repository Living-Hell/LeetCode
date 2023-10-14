// M1
// Using bucket sort
// Faster than 84.73% (137ms)

class Solution
{
public:
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

// M2
// Using Radix sort + count sort
// Faster than 18.98% (228ms)

class Solution
{
public:
    // Using Radix Sort
    int maximumGap(vector<int> &nums)
    {
        int n = nums.size();
        int maxe = *max_element(nums.begin(), nums.end());
        int div = 1;

        while ((maxe / div) >= 1)
        {
            vector<int> ans(n);
            vector<int> count(10, 0);

            for (int num : nums)
                count[(num / div) % 10]++;

            for (int i = 1; i < 10; i++)
                count[i] += count[i - 1];

            for (int i = n - 1; i >= 0; i--)
            {
                int num = (nums[i] / div) % 10;
                ans[count[num] - 1] = nums[i];
                count[num]--;
            }

            for (int i = 0; i < n; i++)
                nums[i] = ans[i];

            div *= 10;
        }

        int gap = 0;
        for (int i = 1; i < n; i++)
            gap = max(gap, nums[i] - nums[i - 1]);

        return gap;
    }
};