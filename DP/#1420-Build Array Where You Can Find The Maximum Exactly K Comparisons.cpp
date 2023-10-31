// M1
// Using recursion and memoisation
// Faster than 26.99% (136ms)

class Solution
{
public:
    int mod = 1e9 + 7;
    int n, k, m;
    int dp[51][101][51];
    int solve(int ind, int cmax, int scost)
    {
        if (ind == n)
        {
            if (scost == k)
                return 1;
            else
                return 0;
        }
        int ans = 0;

        if (dp[ind][cmax][scost] != -1)
            return dp[ind][cmax][scost];

        for (int i = 1; i <= m; i++)
        {
            if (i > cmax)
                ans = (ans + solve(ind + 1, i, scost + 1)) % mod;
            else
                ans = (ans + solve(ind + 1, cmax, scost)) % mod;
        }

        return dp[ind][cmax][scost] = ans % mod;
    }
    int numOfArrays(int n, int m, int k)
    {
        this->n = n;
        this->k = k;
        this->m = m;
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0);
    }
};