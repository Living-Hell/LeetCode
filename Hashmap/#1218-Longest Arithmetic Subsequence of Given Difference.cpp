// M1
// Using Hashmap
// Faster than 79.58% (104ms)

class Solution
{
public:
    int longestSubsequence(vector<int> &arr, int diff)
    {
        unordered_map<int, int> mp;
        int n = arr.size(), ans = 1;
        for (int i = 0; i < n; i++)
        {
            if (mp.find(arr[i] - diff) != mp.end())
                mp[arr[i]] = mp[arr[i] - diff] + 1;
            else
                mp[arr[i]] = 1;
            ans = max(ans, mp[arr[i]]);
        }
        return ans;
    }
};