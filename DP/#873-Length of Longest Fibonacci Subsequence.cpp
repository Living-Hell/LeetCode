// M1
// Using recursion + memoization
// Faster than 68.48% (359 ms)

class Solution
{
public:
    int dp[1001][1001];
    int solve(vector<int> &arr, int i, int j, unordered_map<int, int> &mp)
    {
        if (dp[i][j] != -1)
            return dp[i][j];
        if (mp.find(arr[i] + arr[j]) == mp.end())
            return 0;
        return dp[i][j] = 1 + solve(arr, j, mp[arr[i] + arr[j]], mp);
    }
    int lenLongestFibSubseq(vector<int> &arr)
    {
        int n = arr.size();
        unordered_map<int, int> mp;
        memset(dp, -1, sizeof(dp));

        for (int i = 0; i < n; i++)
        {
            mp[arr[i]] = i;
        }

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (mp.find(arr[i] + arr[j]) != mp.end())
                {
                    int temp = 2 + solve(arr, i, j, mp);
                    ans = max(ans, temp);
                }
            }
        }
        return ans;
    }
};