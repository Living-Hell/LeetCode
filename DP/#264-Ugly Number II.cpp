// M1
// Using Orrdered Sets
// Faster than 22.72% (98 ms)

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        set<long long> ugly = {1};
        int count = 0;
        for (auto i = ugly.begin(); i != ugly.end(); i++, count++)
        {
            if (count == n - 1)
                return *i;
            ugly.insert((*i) * 2);
            ugly.insert((*i) * 3);
            ugly.insert((*i) * 5);
        }
        return -1;
    }
};

// M2
// Using Dp
// Faster than 83.39% (5ms)

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        long long dp[n];
        int ind1 = 0, ind2 = 0, ind3 = 0;
        dp[0] = 1;
        for (int i = 1; i < n; i++)
        {
            dp[i] = min(dp[ind1] * 2, min(dp[ind2] * 3, dp[ind3] * 5));
            if (dp[i] == dp[ind1] * 2)
                ind1++;
            if (dp[i] == dp[ind2] * 3)
                ind2++;
            if (dp[i] == dp[ind3] * 5)
                ind3++;
        }
        return dp[n - 1];
    }
};