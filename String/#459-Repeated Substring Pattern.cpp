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

// M2
// Using substr
// Faster than 86.64% (13ms)

class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        string t = s + s;
        if (t.substr(1, t.size() - 2).find(s) != -1)
            return 1;
        return 0;
    }
};