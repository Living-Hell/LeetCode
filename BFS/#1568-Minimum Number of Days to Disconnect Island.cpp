//M1
//Using BFS and counting Islands
//Faster than 21.55% (134ms)

class Solution {
public:
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int bfs(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, 0));
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] and !vis[i][j]) {
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vis[i][j] = 1;
                    count++;
                    if (count > 1)
                        return 0;
                    while (!q.empty()) {
                        auto [x, y] = q.front();
                        q.pop();
                        for (auto& p : dir) {
                            int x1 = x + p.first, y1 = y + p.second;
                            if (x1 >= 0 and x1 < m and y1 >= 0 and y1 < n and
                                !vis[x1][y1] and grid[x1][y1]) {
                                q.push({x1, y1});
                                vis[x1][y1] = 1;
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
    int minDays(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        if (!bfs(grid))
            return 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    grid[i][j] = 0;
                    int res = bfs(grid);
                    if (res != 1)
                        return 1;
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};
