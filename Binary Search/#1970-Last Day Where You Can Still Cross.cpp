//M1
//Using binary search and bfs
//Faster than 23.07% (609ms)

class Solution {
public:
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool solve(int row, int col, vector<vector<int>>& cells, int days) {
        vector<vector<int>> matrix(row, vector<int>(col, 1));
        for (int i = 0; i < days; i++) {
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            matrix[r][c] = 0;
        }

        queue<pair<int, int>> q;
        vector<vector<bool>> vis(row, vector<bool>(col, 0));

        for (int j = 0; j < col; j++) {
            if (matrix[0][j]) {
                q.push({0, j});
                vis[0][j] = 1;
            }
        }

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (x == row - 1)
                return 1;
            for (auto& d : dir) {
                int i = x + d.first, j = y + d.second;
                if (i >= 0 and i < row and j >= 0 and j < col and !vis[i][j] and
                    matrix[i][j]) {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
        return 0;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int st = 1, end = cells.size() - 1, res = 0;
        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (solve(row, col, cells, mid)) {
                st = mid + 1;
                res = mid;
            } else
                end = mid - 1;
        }
        return res;
    }
};
