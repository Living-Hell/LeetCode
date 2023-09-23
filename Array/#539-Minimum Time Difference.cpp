// M1
// Using sorting
// Faster than 97.08% (6ms)

class Solution
{
public:
    int findMinDifference(vector<string> &timePoints)
    {
        vector<int> times;
        for (const string &a : timePoints)
        {
            int hr = (a[0] - '0') * 10 + a[1] - '0';
            int min = (a[3] - '0') * 10 + a[4] - '0';
            int time = hr * 60 + min;
            times.push_back(time);
        }
        sort(times.begin(), times.end());
        int n = times.size();
        int last = times[n - 1];
        int ans = 24 * 60;
        for (int i = 0; i < n - 1; i++)
            ans = min(ans, min(times[i + 1] - times[i], 24 * 60 - last + times[i]));
        return ans;
    }
};