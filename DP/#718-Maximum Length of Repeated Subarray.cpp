// M1
// Using 2D DP
// Faster than 25.15% (268ms)

class Solution
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        int ans = 0, n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1));
        for (int i = 0; i <= n1; i++)
            dp[i][0] = 0;
        for (int i = 0; i <= n2; i++)
            dp[0][i] = 0;
        for (int i = 1; i <= n1; i++)
        {
            for (int j = 1; j <= n2; j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                else
                    dp[i][j] = 0;
                ans = max(dp[i][j], ans);
            }
        }
        return ans;
    }
};