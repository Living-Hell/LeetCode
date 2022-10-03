//M1
//Recursion and backtracking
//Faster than 86.56% (3ms)

class Solution {
public:
    int paths(vector<vector<int>> &dp, vector<vector<int>>& obstacleGrid, int i, int j, int m, int n){
        
        if(i>=m || j>=n || obstacleGrid[i][j])
            return 0;
        if(i==m-1 && j==n-1)
            return 1;
        if(dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = paths(dp,obstacleGrid,i+1,j,m,n) + paths(dp,obstacleGrid,i,j+1,m,n);
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        
        vector<vector<int>> dp(m,vector<int> (n,-1));
        
        return paths(dp, obstacleGrid, 0, 0, m, n);
        
    }
};