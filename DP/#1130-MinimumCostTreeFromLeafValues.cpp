// M1
// Using Recursion for Top Down Approach
// Faster than 60.25% (36ms)

class Solution
{
public:
    int solve(vector<int> &arr, map<pair<int, int>, int> &mp, int i, int j, vector<vector<int>> &dp)
    {
        if (i == j)
            return 0;
        int ans = INT_MAX;
        if (dp[i][j] != -1)
            return dp[i][j];
        for (int k = i; k < j; k++)
        {
            ans = min(ans, mp[{i, k}] * mp[{k + 1, j}] + solve(arr, mp, i, k, dp) + solve(arr, mp, k + 1, j, dp));
        }
        return dp[i][j] = ans;
    }
    int mctFromLeafValues(vector<int> &arr)
    {
        map<pair<int, int>, int> mp;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            mp[{i, i}] = arr[i];
            for (int j = i + 1; j < n; j++)
            {
                mp[{i, j}] = max(arr[j], mp[{i, j - 1}]);
            }
        }
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(arr, mp, 0, n - 1, dp);
    }
};