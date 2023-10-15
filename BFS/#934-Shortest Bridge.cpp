// M1
// Using DFS + BFS
// Faster than 99.54% (22ms)

class Solution
{
public:
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    queue<pair<int, int>> q;
    void dfs(vector<vector<int>> &grid, int n, int x, int y)
    {
        grid[x][y] = 2;
        q.push({x, y});
        for (auto p : dir)
        {
            int i = p.first + x, j = y + p.second;
            if (i >= 0 and i < n and j >= 0 and j < n and grid[i][j] == 1)
            {
                dfs(grid, n, i, j);
            }
        }
    }
    int shortestBridge(vector<vector<int>> &grid)
    {
        int n = grid.size();
        bool check = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j])
                {
                    dfs(grid, n, i, j);
                    check = 1;
                    break;
                }
            }
            if (check)
                break;
        }

        int ans = 0;
        while (q.size())
        {
            int sz = q.size();
            while (sz--)
            {
                auto top = q.front();
                q.pop();
                int x = top.first, y = top.second;
                for (auto p : dir)
                {
                    int i = p.first + x, j = y + p.second;
                    if (i >= 0 and i < n and j >= 0 and j < n)
                    {
                        if (grid[i][j] == 1)
                            return ans;
                        else if (grid[i][j] == 0)
                        {
                            q.push({i, j});
                            grid[i][j] = 2;
                        }
                    }
                }
            }
            ans++;
        }
        return ans;
    }
};
