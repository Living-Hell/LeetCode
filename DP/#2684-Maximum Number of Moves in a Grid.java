//M1
//Using DP (recursion + memoisation)
//Faster than 100% (5ms)

class Solution {
    int[][] dp;

    public int helper(int[][] grid, int m, int n, int i, int j, int prev) {
        if (i < 0 || j < 0 || i >= m || j >= n || prev >= grid[i][j])
            return 0;
        int res = 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int rightUp = helper(grid, m, n, i - 1, j + 1, grid[i][j]);
        int right = helper(grid, m, n, i, j + 1, grid[i][j]);
        int rightBelow = helper(grid, m, n, i + 1, j + 1, grid[i][j]);

        res = 1 + Math.max(rightUp, Math.max(right, rightBelow));

        return dp[i][j] = res;
    }

    public int maxMoves(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        int ans = 0;
        dp = new int[m + 1][n + 1];
        for (int[] i : dp)
            Arrays.fill(i, -1);
        for (int i = 0; i < m; i++) {
            ans = Math.max(ans, helper(grid, m, n, i, 0, -1));
        }
        return ans - 1;
    }
}
