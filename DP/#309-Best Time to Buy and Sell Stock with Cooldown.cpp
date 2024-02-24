// M1
// Using 3 vectors to store the state and dp on them
// Faster than 100% (0ms)

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int> a0(n), a1(n), a2(n);
        a0[0] = 0;
        a1[0] = -prices[0];
        a2[0] = INT_MIN;

        for (int i = 1; i < n; i++)
        {
            a0[i] = max(a0[i - 1], a2[i - 1]);
            a1[i] = max(a0[i - 1] - prices[i], a1[i - 1]);
            a2[i] = max(a1[i - 1] + prices[i], a2[i - 1]);
        }
        return max(a2[n - 1], a0[n - 1]);
    }
};