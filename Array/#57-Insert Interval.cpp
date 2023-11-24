// M1
// Using while loop
// Faster than 59.54% (13 ms)

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        int n = intervals.size();
        int j = 0;
        vector<vector<int>> ans;

        while (j < n and intervals[j][1] < newInterval[0])
            ans.push_back(intervals[j++]);

        int st = newInterval[0], end = newInterval[1];

        while (j < n and intervals[j][0] <= newInterval[1])
        {
            end = max(end, intervals[j][1]);
            st = min(st, intervals[j++][0]);
        }

        ans.push_back({st, end});

        while (j < n)
            ans.push_back(intervals[j++]);

        return ans;
    }
};