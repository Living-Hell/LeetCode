// M1
// Using mod and string
// Faster than 100% (0ms)

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t ans = 0;

        string s;

        while (n > 0)
        {
            s.push_back((n & 1) + '0');
            n /= 2;
        }

        int m = s.size();
        while (m < 32)
            s.push_back('0'), m++;

        for (int i = 0; i < m; i++)
        {
            ans += pow(2, i) * (s[m - i - 1] - '0');
        }

        return ans;
    }
};