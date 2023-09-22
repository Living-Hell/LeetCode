// M1
// Using simulation
// Faster than 43.4% (180ms)

class Solution
{
public:
    int largestOverlap(vector<vector<int>> &img1, vector<vector<int>> &img2)
    {
        int n = img1.size();
        int ans = 0;
        vector<pair<int, int>> v1, v2;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (img1[i][j])
                    v1.push_back({i, j});
                if (img2[i][j])
                    v2.push_back({i, j});
            }
        }

        map<pair<int, int>, int> mp;
        for (auto p1 : v1)
        {
            for (auto p2 : v2)
            {
                int x = p1.first - p2.first;
                int y = p1.second - p2.second;
                mp[{x, y}]++;
                ans = max(ans, mp[{x, y}]);
            }
        }
        return ans;
    }
};