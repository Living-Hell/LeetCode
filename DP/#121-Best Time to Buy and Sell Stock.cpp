// M1
// Using DP
// Faster than 34.86% (101 ms)

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int buyp = INT_MAX, n = prices.size(), ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (prices[i] <= buyp)
            {
                buyp = prices[i];
            }
            ans = max(ans, prices[i] - buyp);
        }
        return ans;
    }
};