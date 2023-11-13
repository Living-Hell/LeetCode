// M1
// Using two pointers
// Faster than 48.29% (3 ms)

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int i = s.size() - 1;
        while (i >= 0 and s[i] == ' ')
            i--;
        int j = i;
        while (j >= 0 and s[j] != ' ')
            j--;
        return i - j;
    }
};