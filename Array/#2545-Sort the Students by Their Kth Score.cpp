// M1
// Using sorting
// Faster than 92.8% (51ms)

class Solution
{
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>> &score, int k)
    {
        sort(score.begin(), score.end(), [&](const vector<int> &a, const vector<int> &b)
             { return a[k] > b[k]; });
        return score;
    }
};