// M1
// Using recursion and memoization
// Faster than 22.28% (26 ms)

class Solution
{
public:
    int dp[1002][101][3];
    int solve(vector<int> &prices, int k, bool bought, int ind)
    {
        if (ind == prices.size() or k == 0)
            return 0;

        if (dp[ind][k][bought] != -1)
            return dp[ind][k][bought];

        int ans = 0;

        if (bought)
            ans = max({ans, solve(prices, k, 1, ind + 1), solve(prices, k - 1, 0, ind + 1) + prices[ind]});
        else
            ans = max({ans, solve(prices, k, 0, ind + 1), solve(prices, k, 1, ind + 1) - prices[ind]});

        return dp[ind][k][bought] = ans;
    }
    int maxProfit(int k, vector<int> &prices)
    {
        memset(dp, -1, sizeof(dp));
        return solve(prices, k, 0, 0);
    }
};