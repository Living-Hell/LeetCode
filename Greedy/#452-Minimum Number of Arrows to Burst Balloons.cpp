// M1
// Using sorting and greedy
// Faster than 62.2% (365 ms)

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {
        sort(points.begin(), points.end(), [&](const vector<int> &a, const vector<int> &b)
             {
            if(a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1]; });

        int n = points.size();
        int i = 0, j = 0, ans = 0;
        while (j < n)
        {
            while (j < n and points[j][0] <= points[i][1])
                j++;
            i = j;
            j++;
            ans++;
        }
        if (i < n)
            ans++;
        return ans;
    }
};