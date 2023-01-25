//M1
//Using DP
//Faster than 40.25%(625ms)

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n,0));

        for(int g=0; g<n; g++){
            for(int i=0, j=g; j<n; i++, j++){
                for(int k=i; k<=j; k++){
                    int left = k==i? 0: dp[i][k-1];
                    int right = k==j? 0: dp[k+1][j];
                    int val = (i==0? 1:nums[i-1])*nums[k]*(j==n-1? 1:nums[j+1]);
                    dp[i][j] = max(dp[i][j], left + right + val);
                }
            }
        }
        return dp[0][n-1];        
    }
};