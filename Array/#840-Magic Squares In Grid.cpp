//M1
//Using Brute Force
//Faster than 100% (0ms)

class Solution {
public:
    bool checkRCSum(int arr[]) {
        if (arr[0] != arr[1] or arr[1] != arr[2] or arr[0] != arr[2])
            return 0;
        return 1;
    }
    bool solve(vector<vector<int>>& grid, int x, int y) {
        int rowSum[3] = {0}, colSum[3] = {0};
        bool check[9] = {0};
        for (int i = x; i < x + 3; i++) {
            for (int j = y; j < y + 3; j++) {
                if (grid[i][j] < 1 or grid[i][j] > 9)
                    return 0;
                if (check[grid[i][j] - 1])
                    return 0;
                check[grid[i][j] - 1] = 1;
                rowSum[i - x] += grid[i][j];
                colSum[j - y] += grid[i][j];
            }
        }

        if (!checkRCSum(rowSum) or !checkRCSum(colSum))
            return 0;

        int diag1 = grid[x][y] + grid[x + 1][y + 1] + grid[x + 2][y + 2];
        int diag2 = grid[x + 2][y] + grid[x + 1][y + 1] + grid[x][y + 2];
        if (diag1 != diag2 or diag1 != rowSum[0] or diag1 != colSum[0])
            return 0;
        return 1;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int res = 0, m = grid.size(), n = grid[0].size();
        if (m < 3 or n < 3)
            return 0;
        for (int i = 0; i < m - 2; i++) {
            for (int j = 0; j < n - 2; j++) {
                res += solve(grid, i, j);
            }
        }
        return res;
    }
};
