// M1
// Using hashmap
// Faster than 100% (1712 ms)

class Solution
{
public:
    int countPairs(vector<vector<int>> &coordinates, int k)
    {
        int n = coordinates.size();
        map<pair<int, int>, int> mp;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int x = coordinates[i][0], y = coordinates[i][1];
            for (int xsum = 0; xsum <= k; xsum++)
            {
                ans += mp[{xsum ^ x, (k - xsum) ^ y}];
            }
            mp[{x, y}]++;
        }
        return ans;
    }
};