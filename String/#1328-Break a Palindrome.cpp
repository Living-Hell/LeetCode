// M1
// Using Greedy approach
// Faster than 100% (0ms)

class Solution
{
public:
    bool isPalindrome(string S)
    {
        for (int i = 0; i < S.length() / 2; i++)
        {
            if (S[i] != S[S.length() - i - 1])
                return 0;
        }
        return 1;
    }
    string breakPalindrome(string s)
    {
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (s[i] > 'a')
            {
                char c = s[i];
                s[i] = 'a';
                if (!isPalindrome(s))
                    return s;
                s[i] = c;
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (s[i] < 'z')
            {
                s[i]++;
                if (!isPalindrome(s))
                    return s;
                s[i]--;
            }
        }
        return "";
    }
};