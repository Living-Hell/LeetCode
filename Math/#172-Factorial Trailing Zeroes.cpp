// M1
// Using Math and simulation
// Faster than 100% (0ms)

class Solution
{
public:
    int trailingZeroes(int n)
    {
        int ans = 0;
        for (int i = 5; n / i > 0; i *= 5)
            ans += n / i;
        return ans;
    }
};