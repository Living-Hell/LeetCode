// M1
// Using sorting and hashing
// Faster than 87.91% (31 ms)

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {

        int n = strs.size();
        vector<vector<string>> ans;

        vector<string> copy = strs;

        for (int i = 0; i < n; i++)
        {
            sort(copy[i].begin(), copy[i].end());
        }

        unordered_map<string, vector<int>> mp;

        for (int i = 0; i < n; i++)
            mp[copy[i]].push_back(i);

        for (auto i : mp)
        {
            vector<string> temp;
            for (auto j : i.second)
            {
                temp.push_back(strs[j]);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};

// M2
// Using sorting and hashing
// Faster than 77.04% (35 ms)

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        for (const auto &s : strs)
        {
            string t = s;
            sort(t.begin(), t.end());
            mp[t].push_back(s);
        }
        for (const auto &i : mp)
            ans.push_back(i.second);
        return ans;
    }
};