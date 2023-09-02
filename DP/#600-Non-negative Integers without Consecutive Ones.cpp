// M1
// Using Digit DP
// Faster than 13.66% (15ms)

class Solution
{
public:
    int dp[32][2][2];
    int solve(string s, int ind, bool tight, bool last1)
    {
        if (ind == s.size())
        {
            return 1;
        }
        if (dp[ind][tight][last1] != -1)
            return dp[ind][tight][last1];
        int ans = 0;
        int ub = (tight) ? s[ind] - '0' : 1;
        for (int dig = 0; dig <= ub; dig++)
        {
            if (last1 and dig == 1)
                continue;
            else if (last1 and dig == 0)
                ans += solve(s, ind + 1, tight & (dig == ub), 0);
            else if (!last1 and dig == 1)
                ans += solve(s, ind + 1, tight & (dig == ub), 1);
            else
            {
                ans += solve(s, ind + 1, tight & (dig == ub), 0);
            }
        }
        return dp[ind][tight][last1] = ans;
    }
    int findIntegers(int n)
    {
        memset(dp, -1, sizeof(dp));
        string num = "";
        while (n > 0)
        {
            num = to_string(n % 2) + num;
            n /= 2;
        }
        return solve(num, 0, 1, 0);
    }
};