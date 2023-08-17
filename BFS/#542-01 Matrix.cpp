// M1
// Using BFS
// Faster than 95.26% (58ms)

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n));
        queue<pair<int, int>> q;
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        q.push({0, 0});
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    q.push({i, j});
                    ans[i][j] = 0;
                }
                else
                    ans[i][j] = m * n;
            }
        }
        while (!q.empty())
        {
            auto top = q.front();
            q.pop();
            int x = top.first, y = top.second;
            for (auto d : dir)
            {
                int i = d.first + x, j = d.second + y;
                if (i >= 0 and i < m and j >= 0 and j < n and ans[i][j] > ans[x][y] + 1)
                {
                    ans[i][j] = ans[x][y] + 1;
                    q.push({i, j});
                }
            }
        }
        return ans;
    }
};