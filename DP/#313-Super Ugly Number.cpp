// M1
// Using Dp
// Faster than 86.64% (183 ms)

class Solution
{
public:
    int nthSuperUglyNumber(int n, vector<int> &primes)
    {
        int m = primes.size();
        int dp[n];
        dp[0] = 1;
        vector<int> count(m, 0);
        for (int i = 1; i < n; i++)
        {
            long curr = INT_MAX;
            for (int j = 0; j < m; j++)
            {
                long val = (long)primes[j] * dp[count[j]];
                curr = min(curr, val);
            }
            dp[i] = curr;
            for (int j = 0; j < m; j++)
            {
                if (curr == (long)primes[j] * dp[count[j]])
                    count[j]++;
            }
        }
        return dp[n - 1];
    }
};