// M1
// Greedy Approach and kinda DP as well
// Faster than 99.51% (103ms)

class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int n = colors.size(), tcost = 0;
        for (int i = 1; i < n; i++)
        {
            if (colors[i] == colors[i - 1])
            {
                tcost += min(neededTime[i], neededTime[i - 1]);
                neededTime[i] = max(neededTime[i], neededTime[i - 1]);
            }
        }
        return tcost;
    }
};