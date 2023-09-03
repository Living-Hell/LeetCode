// M1
// Using Digit Dp
// Faster than 11.33% (5ms)

class Solution
{
public:
    int dp[2][10][2];
    int solve(string num, vector<int> digits, bool tight, int pos, bool isLeading)
    {
        if (pos == num.size())
            return 1;
        if (dp[tight][pos][isLeading] != -1)
            return dp[tight][pos][isLeading];
        int ans = 0;
        int ub = tight ? num[pos] - '0' : 9;
        if (isLeading)
            ans += solve(num, digits, 0, pos + 1, 1);
        for (int i : digits)
        {
            if (i <= ub)
            {
                ans += solve(num, digits, tight & (ub == i), pos + 1, 0);
            }
        }
        return dp[tight][pos][isLeading] = ans;
    }
    int atMostNGivenDigitSet(vector<string> &digits, int n)
    {
        vector<int> dig;
        for (string s : digits)
            dig.push_back(stoi(s));
        string num = to_string(n);
        memset(dp, -1, sizeof(dp));
        return solve(num, dig, 1, 0, 1) - 1;
    }
};