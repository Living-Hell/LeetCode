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