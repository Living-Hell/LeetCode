// M1
// Using set
// Faster than 18.11% (779ms)

class Solution
{
public:
    int minAreaRect(vector<vector<int>> &points)
    {
        int n = points.size();
        set<pair<int, int>> st;
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = 0; j < n; j++)
            {
                int x2 = points[j][0], y2 = points[j][1];
                if (st.count({x1, y2}) and st.count({x2, y1}))
                {
                    int area = abs(x1 - x2) * abs(y1 - y2);
                    if (area)
                        ans = min(ans, area);
                }
            }
            st.insert({x1, y1});
        }
        return ans == INT_MAX ? 0 : ans;
    }
};

// M2
// Using hashmap and set
// Faster than 57.65% (359 ms)

class Solution
{
public:
    int minAreaRect(vector<vector<int>> &points)
    {
        int n = points.size();
        unordered_map<int, set<int>> mp;
        int ans = INT_MAX;

        for (auto i : points)
            mp[i[0]].insert(i[1]);

        for (int i = 0; i < n; i++)
        {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; j++)
            {
                int x2 = points[j][0], y2 = points[j][1];
                if (x1 == x2 or y1 == y2)
                    continue;
                if (mp[x1].count(y2) and mp[x2].count(y1))
                {
                    int area = abs(x1 - x2) * abs(y1 - y2);
                    if (area)
                        ans = min(ans, area);
                }
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};