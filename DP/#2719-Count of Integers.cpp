// M1
// Using Digit DP
// Faster than 30.91%(121ms)
class Solution
{
public:
    long long dp[23][210][2];
    int mod = 1e9 + 7;
    long long solve(string num, int min_sum, int max_sum, int pos, long long curr_sum, bool tight)
    {
        if (curr_sum > max_sum)
            return 0;
        if (pos == num.size())
            return (curr_sum >= min_sum) and (curr_sum <= max_sum);
        if (dp[pos][curr_sum][tight] != -1)
            return dp[pos][curr_sum][tight] % mod;
        int ub = tight ? num[pos] - '0' : 9;
        long long ans = 0;
        for (int i = 0; i <= ub; i++)
        {
            ans = (ans % mod + solve(num, min_sum, max_sum, pos + 1, (curr_sum + i) % mod, tight & (i == ub)) % mod) % mod;
        }
        return dp[pos][curr_sum][tight] = ans % mod;
    }
    int count(string num1, string num2, int min_sum, int max_sum)
    {
        memset(dp, -1, sizeof(dp));
        long long ans1 = solve(num1, min_sum, max_sum, 0, 0, 1) % mod;
        memset(dp, -1, sizeof(dp));
        long long ans2 = solve(num2, min_sum, max_sum, 0, 0, 1) % mod;
        int ans = (int)ans2 - ans1;
        int digitSum = 0;
        for (char c : num1)
            digitSum += c - '0';
        if (digitSum <= max_sum && digitSum >= min_sum)
        {
            ans++;
        }
        return ans < 0 ? ans + mod : ans;
    }
};