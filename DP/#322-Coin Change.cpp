// M1
// using DP
// Faster than 91.4% (62ms)

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {

        int n = coins.size();
        vector<long long int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = coins[i]; j <= amount; j++)
            {
                dp[j] = min(dp[j - coins[i]] + 1, dp[j]);
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
