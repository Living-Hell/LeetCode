//M1
//Using recursion and memoisation
//Faster than 95.36% (27ms)

class Solution {
public:
    int dp[70][70][70];
    int solve(vector<vector<int>>& grid, int m, int n, int r, int c1, int c2) {
        if (r == m)
            return 0;
        int res = 0;

        if (dp[r][c1][c2] != -1)
            return dp[r][c1][c2];

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int y1 = c1 + i, y2 = c2 + j;
                if (y1 < n and y1 >= 0 and y2 < n and y2 >= 0) {
                    res = max(res, solve(grid, m, n, r + 1, y1, y2));
                }
            }
        }

        int cherries = grid[r][c1] + grid[r][c2];
        res += c1 == c2 ? cherries / 2 : cherries;
        return dp[r][c1][c2] = res;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        return solve(grid, grid.size(), grid[0].size(), 0, 0, grid[0].size() - 1);
    }
};
