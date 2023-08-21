// M1
// using substr
// Faster than 5.89% (1044 ms)

class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        int n = s.size();
        for (int i = 1; i <= n / 2; i++)
        {
            string temp = s.substr(0, i);
            string ans = "";
            for (int j = 0; j < n / i; j++)
                ans += temp;
            if (ans == s)
                return 1;
        }
        return 0;
    }
};