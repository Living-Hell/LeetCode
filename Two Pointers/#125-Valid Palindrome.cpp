// M1
// Using two pointers
// Faster than 80.72% (4ms)

class Solution
{
public:
    bool isPalindrome(string &s)
    {
        int i = 0;
        for (int j = 0; j < s.size(); j++)
        {
            if (isalnum(s[j]))
                s[i++] = tolower(s[j]);
        }
        s = s.substr(0, i);
        i = 0;
        int j = s.size() - 1;
        while (i <= j)
        {
            if (s[i++] != s[j--])
                return 0;
        }
        return 1;
    }
};