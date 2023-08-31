// M1
// Using 2 Hashmap
// Faster than 41.93% (3ms)
class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, string> mp;
        vector<string> v;
        string t = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
                t.push_back(s[i]);
            else
            {
                v.push_back(t);
                t = "";
            }
        }
        v.push_back(t);

        if (v.size() != pattern.size())
            return 0;

        for (int i = 0; i < pattern.size(); i++)
        {
            if (mp.find(pattern[i]) == mp.end())
            {
                mp[pattern[i]] = v[i];
            }
            else
            {
                if (mp[pattern[i]] != v[i])
                    return 0;
            }
        }

        unordered_map<string, char> mp2;
        for (int i = 0; i < pattern.size(); i++)
        {
            if (mp2.find(v[i]) == mp2.end())
            {
                mp2[v[i]] = pattern[i];
            }
            else
            {
                if (mp2[v[i]] != pattern[i])
                    return 0;
            }
        }
        return 1;
    }
};

// M2
// Using Hashmap ans Set
// Faster than 41.93% (3ms)
class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        unordered_map<char, string> mp;
        vector<string> v;
        string t = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] != ' ')
                t.push_back(s[i]);
            else
            {
                v.push_back(t);
                t = "";
            }
        }
        v.push_back(t);

        if (v.size() != pattern.size())
            return 0;

        set<string> st;

        for (int i = 0; i < pattern.size(); i++)
        {
            if (mp.find(pattern[i]) == mp.end())
            {
                if (st.count(v[i]) > 0)
                    return 0;
                mp[pattern[i]] = v[i];
                st.insert(v[i]);
            }
            else
            {
                if (mp[pattern[i]] != v[i])
                    return 0;
            }
        }

        return 1;
    }
};