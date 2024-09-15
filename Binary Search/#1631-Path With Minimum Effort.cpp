//M1
//Using Binary Search + BFS
//Faster than 7.93% (268ms)

class Solution {
public:
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool solve(vector<vector<int>>& grid, int maxm) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, 0));
        bool flag = 0;
        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0][0] = 1;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (x == m - 1 and y == n - 1) {
                flag = 1;
                break;
            }
            for (auto& p : dir) {
                int i = x + p.first, j = y + p.second;
                if (i >= 0 and i < m and j >= 0 and j < n and !vis[i][j] and
                    abs(grid[i][j] - grid[x][y]) <= maxm) {
                    vis[i][j] = 1;
                    q.push({i, j});
                }
            }
        }
        return flag;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int st = 0, end = 1e6, ans;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (!solve(heights, mid)) {
                st = mid + 1;
            } else {
                end = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }
};
