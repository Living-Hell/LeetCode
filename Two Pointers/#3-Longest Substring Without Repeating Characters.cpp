// M1
// Using 2 pointers
// Faster than 61.88% (14ms)

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        unordered_map<char, int> mp;
        int i = 0, j = 0, ans = 0;
        while (j < n)
        {
            char c = s[j];
            if (mp.find(c) != mp.end())
            {
                while (i < n and s[i] != c)
                    mp.erase(s[i++]);
                if (i < n)
                    mp[c] = 0, i++;
            }
            mp[c]++;
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};