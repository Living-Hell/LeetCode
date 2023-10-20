// M1
// Using sorting
// Faster than 77.78% (147ms)

class Solution
{
public:
    int carFleet(int target, vector<int> &pos, vector<int> &speed)
    {
        int n = speed.size();
        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++)
        {
            v[i] = {pos[i], speed[i]};
        }

        int ans = 0;
        sort(v.begin(), v.end());
        float curr_max = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            float time = (target - v[i].first) / (float)v[i].second;
            if (time > curr_max)
            {
                curr_max = time;
                ans++;
            }
        }

        return ans;
    }
};