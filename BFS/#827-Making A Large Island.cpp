// M1
// Using BFS and hashmap
// Faster than 10.68% (810 ms)

class Solution
{
public:
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int check(vector<vector<int>> &grid, int n, int i, int j, unordered_map<int, int> &area)
    {
        int count = 0;
        unordered_set<int> st;
        if (i > 0)
            st.insert(grid[i - 1][j]);
        if (j > 0)
            st.insert(grid[i][j - 1]);
        if (i < n - 1)
            st.insert(grid[i + 1][j]);
        if (j < n - 1)
            st.insert(grid[i][j + 1]);
        for (int i : st)
            count += area[i];
        return count;
    }
    int bfs(vector<vector<int>> &grid, int n, int i, int j, vector<vector<bool>> &vis, int counter)
    {
        vis[i][j] = 1;
        grid[i][j] = counter;
        queue<pair<int, int>> q;
        int ans = 0;
        q.push({i, j});
        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            ans++;
            grid[x][y] = counter;
            for (int i = 0; i < 4; i++)
            {
                int ix = x + dx[i], iy = y + dy[i];
                if (ix >= 0 and ix < n and iy >= 0 and iy < n and !vis[ix][iy] and grid[ix][iy] == 1)
                {
                    q.push({ix, iy});
                    vis[ix][iy] = 1;
                }
            }
        }
        return ans;
    }
    int largestIsland(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int ans = 0, counter = 2;
        unordered_map<int, int> area;
        vector<vector<bool>> vis(n, vector<bool>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1 and !vis[i][j])
                {
                    area[counter++] = bfs(grid, n, i, j, vis, counter);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    int val = check(grid, n, i, j, area) + 1;
                    ans = max(ans, val);
                }
            }
        }
        return ans == 0 ? n * n : ans;
    }
};