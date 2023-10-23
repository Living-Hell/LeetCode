// M1
// Using recursion and memoisation
// Faster than 70.44% (12ms)

class Solution
{
public:
    int dp[501][501];
    int solve(vector<int> &nums1, vector<int> &nums2, int i, int j)
    {
        if (i == nums1.size() or j == nums2.size())
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = 0, temp1 = 0;
        if (nums1[i] == nums2[j])
        {
            temp1 = 1 + solve(nums1, nums2, i + 1, j + 1);
        }
        int temp2 = max(solve(nums1, nums2, i, j + 1), solve(nums1, nums2, i + 1, j));
        ans = max(temp1, temp2);
        return dp[i][j] = ans;
    }
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2)
    {
        memset(dp, -1, sizeof(dp));
        return solve(nums1, nums2, 0, 0);
    }
};