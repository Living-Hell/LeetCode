// M1
// Using Recursion and memoization
// Faster than 100% (0ms)

class Solution
{
public:
    double solve(int a, int b, map<pair<int, int>, double> &mp)
    {
        if (a <= 0 and b <= 0)
            return 0.5;
        if (a <= 0)
            return 1.0;
        if (b <= 0)
            return 0.0;
        if (mp.find({a, b}) != mp.end())
            return mp[{a, b}];
        double ans = 0.0;
        ans += solve(a - 100, b, mp);
        ans += solve(a - 75, b - 25, mp);
        ans += solve(a - 50, b - 50, mp);
        ans += solve(a - 25, b - 75, mp);
        mp[{a, b}] = ans * 0.25;
        return mp[{a, b}];
    }
    double soupServings(int n)
    {
        if (n >= 4800)
            return 1.0;
        map<pair<int, int>, double> mp;
        return solve(n, n, mp);
    }
};