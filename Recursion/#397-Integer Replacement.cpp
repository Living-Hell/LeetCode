// M1
// Using Recursion and memoization
// Faster than 100% (0ms)

class Solution
{
public:
    unordered_map<int, int> mp;
    int solve(long long int n)
    {
        if (n <= 1)
            return 0;
        if (mp.find(n) != mp.end())
            return mp[n];
        if (n & 1)
            return mp[n] = 1 + min(solve(n - 1), solve(n + 1));
        else
            return mp[n] = 1 + solve(n / 2);
    }
    int integerReplacement(int n)
    {
        return solve(n);
    }
};