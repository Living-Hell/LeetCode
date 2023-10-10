// M1
// Using simulation
// Faster than 92.65% (4ms)

class Solution
{
public:
    int maxDistToClosest(vector<int> &seats)
    {
        int n = seats.size();
        vector<int> v;
        for (int i = 0; i < n; i++)
            if (seats[i])
                v.push_back(i);
        int ans = max(v[0], n - 1 - v.back());
        for (int i = 1; i < v.size(); i++)
            ans = max(ans, (v[i] - v[i - 1]) / 2);
        return ans;
    }
};