// M1
// Using hashmap
// Faster than 100% (0ms)

class Solution
{
public:
    string customSortString(string order, string s)
    {
        int a[26] = {0};
        for (char c : s)
            a[c - 'a']++;
        string ans;
        for (char c : order)
        {
            for (int i = 0; i < a[c - 'a']; i++)
                ans.push_back(c);
            a[c - 'a'] = 0;
        }
        for (int i = 0; i < 26; i++)
        {
            if (a[i] > 0)
            {
                for (int j = 0; j < a[i]; j++)
                    ans.push_back(i + 'a');
            }
        }
        return ans;
    }
};