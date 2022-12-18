//M1
//Using DP
//Faster than 85.42% (97ms)

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {

        int m = matrix.size(), n = matrix[0].size();
        int ans=INT_MIN;
        vector<vector<int>> dp(m,vector<int> (n,0));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] - '0'>0 && i>0 &&j>0){
                    dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]))+1;
                }
                else
                    dp[i][j] = matrix[i][j]-'0';
                ans = max(ans,dp[i][j]);
            }
        }
        return ans*ans;
    }
};