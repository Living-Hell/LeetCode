//M1
//Recursion & DP
//Faster than 100% (0ms)

class Solution {
public:
    int paths(vector<vector<int>> &dp, int i, int j, int m, int n){
        
        if(i>=m || j>=n)
            return 0;
        if(i==m-1 && j==n-1)
            return 1;
        if(dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = paths(dp,i+1,j,m,n) + paths(dp,i,j+1,m,n);
    }    
    
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m,vector<int> (n,-1));
        
        return paths(dp, 0, 0, m, n);
        
    }
};

//M2
//Recursion
//TLE

class Solution {
public:
    int paths(int i, int j, int m, int n){
        
        if(i>=m || j>=n)
            return 0;
        if(i==m-1 && j==n-1)
            return 1;
        return paths(i+1,j,m,n) + paths(i,j+1,m,n);
    }    
    
    int uniquePaths(int m, int n) {
        
        return paths(0, 0, m, n);
        
    }
};