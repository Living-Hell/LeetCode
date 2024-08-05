//M1
//Using DFS and DP
//Faster than 64.56% (30ms)

class Solution {
public:
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int dp[201][201];

    int solve(vector<vector<int>>& matrix, int i, int j) {
        if (dp[i][j] != -1)
            return dp[i][j];
        int len = 0;
        for (auto& p : dir) {
            int x = p.first + i, y = p.second + j;
            if (x >= 0 and x < matrix.size() and y >= 0 and
                y < matrix[0].size() and matrix[x][y] > matrix[i][j]) {
                len = max(len, 1 + solve(matrix, x, y));
            }
        }
        return dp[i][j] = len;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, solve(matrix, i, j));
            }
        }
        return res + 1;
    }
};
