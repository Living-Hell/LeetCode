// M1
// Using maths
// Faster than 100% (0ms)

class Solution
{
public:
    bool escapeGhosts(vector<vector<int>> &ghosts, vector<int> &target)
    {
        int tdist = abs(target[0]) + abs(target[1]);
        int gdist = INT_MAX;
        for (auto p : ghosts)
            gdist = min(gdist, abs(p[0] - target[0]) + abs(p[1] - target[1]));
        if (tdist < gdist)
            return 1;
        return 0;
    }
};