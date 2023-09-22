// M1
// Using hashmap
// Faster than 58.19% (37 ms)

class Solution
{
public:
    int leastBricks(vector<vector<int>> &wall)
    {
        int rows = wall.size();
        long long col = accumulate(wall[0].begin(), wall[0].end(), 0);
        unordered_map<long long, int> mp;
        for (int i = 0; i < rows; i++)
        {
            long long t = 0;
            for (int w : wall[i])
            {
                t += w;
                if (t < col)
                    mp[t]++;
            }
        }
        int ans = 0;
        for (auto i : mp)
            ans = max(ans, i.second);
        return rows - ans;
    }
};