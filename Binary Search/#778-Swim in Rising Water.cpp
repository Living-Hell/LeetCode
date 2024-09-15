//M1
//Using binary search + BFS
//Faster than 55.46% (14ms)

class Solution {
public:
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool solve(vector<vector<int>>& grid, int maxm) {
        if (grid[0][0] > maxm)
            return 0;
        int n = grid.size();
        vector<vector<bool>> vis(n, vector<bool>(n, 0));
        bool flag = 0;
        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0][0] = 1;

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (x == n - 1 and y == n - 1) {
                flag = 1;
                break;
            }
            for (auto& p : dir) {
                int i = x + p.first, j = y + p.second;
                if (i >= 0 and i < n and j >= 0 and j < n and !vis[i][j] and
                    grid[i][j] <= maxm) {
                    vis[i][j] = 1;
                    q.push({i, j});
                }
            }
        }
        return flag;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int st = 0, end = n * n, ans;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (!solve(grid, mid)) {
                st = mid + 1;
            } else {
                end = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }
};
