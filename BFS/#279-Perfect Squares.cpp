// M1
// Using BFS Search
// Faster than 94.21% (58ms)

class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> options;
        for (int i = 1; i * i <= 1e4; i++)
            options.push_back(i * i);
        reverse(options.begin(), options.end());
        queue<pair<int, int>> q;
        q.push({n, 0});
        while (!q.empty())
        {
            auto p = q.front();
            q.pop();
            int curr = p.first, count = p.second;
            for (int i : options)
            {
                if (curr - i >= 0)
                {
                    q.push({curr - i, count + 1});
                    if (curr - i == 0)
                        return count + 1;
                }
            }
        }
        return -1;
    }
};