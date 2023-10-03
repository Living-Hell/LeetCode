// M1
// Using hashmap
// Faster than 82.85% (8ms)

class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> mp;
        for (char c : s)
            mp[c]++;

        map<int, string> mp2;
        for (auto i : mp)
        {
            int len = i.second;
            char c = i.first;
            mp2[len] += string(len, c);
        }

        string ans;
        for (auto i = mp2.rbegin(); i != mp2.rend(); i++)
            ans += i->second;

        return ans;
    }
};