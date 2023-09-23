// M2
// Using 2-Pointers and frequency table
// Faster than 78.67% (10ms)

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int n1 = s1.size(), n2 = s2.size();
        vector<int> f1(26, 0), f2(26, 0);
        for (const char &c : s1)
            f1[c - 'a']++;
        int l = 0, r = 0;
        while (r < n2)
        {
            f2[s2[r] - 'a']++;
            if (r - l + 1 == n1)
            {
                if (f1 == f2)
                    return 1;
            }
            if (r - l + 1 < n1)
            {
                r++;
            }
            else
            {
                f2[s2[l] - 'a']--;
                l++;
                r++;
            }
        }
        return 0;
    }
};