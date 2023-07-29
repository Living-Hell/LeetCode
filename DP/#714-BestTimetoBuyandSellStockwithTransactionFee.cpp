// M1
// Using vectors
// Faster than 99.9%(70ms)
class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int n = prices.size();
        vector<int> bs(n), ss(n);
        bs[0] = -prices[0], ss[0] = 0;
        for (int i = 1; i < n; i++)
        {
            bs[i] = max(bs[i - 1], ss[i - 1] - prices[i]);
            ss[i] = max(ss[i - 1], bs[i - 1] + prices[i] - fee);
        }
        return ss[n - 1];
    }
};

// M2
// Using 2 pointers
// Faster than 99.75%(75ms)