// M1
// Using greedy
// Faster than 90.18% (3ms)

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int ans = 0, buyp = INT_MAX, sellp = 0, n = prices.size();
        for (int i = 0; i < n; i++)
        {
            if (buyp >= prices[i])
            {
                buyp = prices[i];
                sellp = 0;
            }
            else if (sellp <= prices[i])
            {
                sellp = prices[i];
                ans += prices[i] - buyp;
                buyp = prices[i];
            }
        }
        return ans;
    }
};