// M1
// Using DP and memoization
// Faster than 83.78% (3ms)

class Solution
{
public:
    long long mod = 1e9 + 7;
    long long helper(int n, int goal, int k, int old, vector<vector<long long>> &dp)
    {
        if (goal == 0 and old == n)
            return 1;
        if (goal == 0 or old > n)
            return 0;

        if (dp[old][goal] != -1)
            return dp[old][goal];

        long long ans = 0;
        ans = (ans + ((n - old) * helper(n, goal - 1, k, old + 1, dp)) % mod) % mod;
        if (old > k)
            ans = (ans + ((old - k) * helper(n, goal - 1, k, old, dp)) % mod) % mod;
        return dp[old][goal] = ans % mod;
    }
    int numMusicPlaylists(int n, int goal, int k)
    {
        vector<vector<long long>> dp(n + 1, vector<long long>(goal + 1, -1));
        return helper(n, goal, k, 0, dp);
    }
};