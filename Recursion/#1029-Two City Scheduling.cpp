// M1
// Using recursion and memoization
// Faster than 42.33% (6ms)

class Solution
{
public:
    int dp[52][52];
    int solve(vector<vector<int>> &costs, int ind, int counta, int countb)
    {
        if (ind == costs.size())
        {
            if (counta == 0 and countb == 0)
                return 0;
            else
                return 10000000;
        }
        if (counta < 0 or countb < 0)
            return 10000000;

        if (dp[counta][countb] != -1)
            return dp[counta][countb];

        int tcost = 0;
        tcost += min(costs[ind][0] + solve(costs, ind + 1, counta - 1, countb),
                     costs[ind][1] + solve(costs, ind + 1, counta, countb - 1));

        return dp[counta][countb] = tcost;
    }
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        int n = costs.size() / 2;
        memset(dp, -1, sizeof(dp));
        return solve(costs, 0, n, n);
    }
};

// M2
// Using sorting
// Faster than 42.33% (6ms)
class Solution
{
public:
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        int n = costs.size() / 2, ans = 0;
        sort(costs.begin(), costs.end(), [&](const vector<int> &a, const vector<int> &b)
             { return a[0] - a[1] < b[0] - b[1]; });
        for (int i = 0; i < n; i++)
        {
            ans += costs[i][0] + costs[i + n][1];
        }
        return ans;
    }
};