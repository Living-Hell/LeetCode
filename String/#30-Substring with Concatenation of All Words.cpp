// M1
// Using hashmap
// Faster than 37.39% (2371 ms)

class Solution
{
public:
    bool check(string &s, unordered_map<string, int> mp, int size)
    {
        for (int i = 0; i <= s.size() - size; i += size)
        {
            string sub = s.substr(i, size);
            if (mp[sub] > 0)
                mp[sub]--;
            else
                return 0;
        }
        return 1;
    }
    vector<int> findSubstring(string &s, vector<string> &words)
    {
        int n = s.size(), k = words.size(), m = words[0].size(), total_size = k * m;
        vector<int> ans;
        unordered_map<string, int> mp;

        if (n < total_size)
            return ans;
        for (string s : words)
            mp[s]++;

        for (int i = 0; i <= n - total_size; i++)
        {
            string sub = s.substr(i, total_size);
            if (check(sub, mp, m))
                ans.push_back(i);
        }
        return ans;
    }
};