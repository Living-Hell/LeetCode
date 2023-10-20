// M1
// Using sliding window
// Faster than 61.88% (44ms)

class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int n = nums.size();
        int f1 = 0, maxf = 0;
        int i = 0, j = 0, ans = 0;
        while (j < n)
        {
            if (nums[j])
                f1++;
            maxf = max(maxf, f1);
            while (j - i + 1 - maxf > k)
            {
                if (nums[i])
                    f1--;
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};

// M2
// Using Binary Search
// Faster than 6.79% (61ms)

class Solution
{
public:
    bool checker(vector<int> &nums, int k, int mid)
    {
        int n = nums.size();
        int freq = 0;
        for (int i = 0; i < mid; i++)
        {
            if (nums[i])
                freq++;
        }
        if (mid - freq <= k)
            return 1;

        for (int i = mid; i < n; i++)
        {
            freq = freq - nums[i - mid] + nums[i];
            if (mid - freq <= k)
                return 1;
        }
        return 0;
    }
    int longestOnes(vector<int> &nums, int k)
    {
        int n = nums.size();
        int ans = 0;
        int st = 0, end = n;
        while (st <= end)
        {
            int mid = st + (end - st) / 2;
            if (checker(nums, k, mid))
            {
                ans = max(ans, mid);
                st = mid + 1;
            }
            else
                end = mid - 1;
        }
        return ans;
    }
};