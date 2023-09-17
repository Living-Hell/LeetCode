// M1
// Using backtracking
// Faster than 47ms (64.02%)

class Solution
{
public:
    int solve(int n, int &mask, int curr)
    {
        if (curr > n)
        {
            return 1;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (!((mask >> i) & 1) and (curr % i == 0 or i % curr == 0))
            {
                mask |= (1 << i);
                ans += solve(n, mask, curr + 1);
                mask ^= (1 << i);
            }
        }
        return ans;
    }
    int countArrangement(int n)
    {
        int mask = 0;
        return solve(n, mask, 1);
    }
};