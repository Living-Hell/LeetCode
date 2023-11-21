// M1
// Using simulation and a bits of math
// Faster than 93.85% (4ms)

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
            return s;
        int n = s.size();
        string ans = "";
        int inc = (numRows - 1) * 2;
        for (int i = 0; i < numRows; i++)
        {
            for (int r = i; r < n; r += inc)
            {
                ans += s[r];
                if (i > 0 and i < numRows - 1 and r + inc - (2 * i) < n)
                    ans += s[r + inc - (2 * i)];
            }
        }
        return ans;
    }
};
