// M1
// Using sorting and binary search
// Faster than 99.69% (44ms)

class Solution
{
public:
    vector<int> findRightInterval(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        vector<pair<int, int>> stime;
        for (int i = 0; i < n; i++)
        {
            stime.push_back({intervals[i][0], i});
        }
        sort(stime.begin(), stime.end());
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            int end = intervals[i][1];
            int low = 0, high = n;
            int temp = -1;
            while (low < high)
            {
                int mid = (low + high) / 2;
                if (stime[mid].first < end)
                    low = mid + 1;
                else
                {
                    high = mid;
                    temp = stime[mid].second;
                }
            }
            ans[i] = temp;
        }
        return ans;
    }
};