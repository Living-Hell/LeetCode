// M1
// Using hashmap and mod
// Faster than 95.67% (105 ms)

class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (int i : nums)
            mp[i]++;
        int ans = 0;
        for (auto i : mp)
        {
            int f = i.second;
            if (f == 1)
                return -1;
            ans += f / 3;
            ans += (f % 3) != 0;
        }
        return ans;
    }
};