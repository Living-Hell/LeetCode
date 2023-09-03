// M1
// Using Digit DP
// Faster than 52.16%(2ms)

class Solution
{
public:
    int dp[10][2][10];
    int helper(string num, int pos, int tight, int count1)
    {
        if (pos == num.size())
            return count1;
        if (dp[pos][tight][count1] != -1)
            return dp[pos][tight][count1];
        int ub = tight ? num[pos] - '0' : 9;
        int ans = 0;
        for (int dig = 0; dig <= ub; dig++)
        {
            if (dig == 1)
                ans += helper(num, pos + 1, tight & (dig == ub), count1 + 1);
            else
                ans += helper(num, pos + 1, tight & (dig == ub), count1);
        }
        return dp[pos][tight][count1] = ans;
    }
    int countDigitOne(int n)
    {
        string num = to_string(n);
        memset(dp, -1, sizeof(dp));
        return helper(num, 0, 1, 0);
    }
};