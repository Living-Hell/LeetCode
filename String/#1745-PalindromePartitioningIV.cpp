//M1
//Using Precomputation(DP) and backtracking
//Faster than 63.46%(366ms)

class Solution {
public:
    bool checkPartitioning(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n,0));
        
        for(int gap=0; gap<n; gap++){
            for(int i=0, j=gap; j<n; j++, i++){
                if(gap==0) 
                    dp[i][j]=1;
                else if(gap==1){
                    if(s[j] == s[j-1])
                        dp[i][j] = 1;
                    else
                        dp[i][j]=0;
                }
                else{
                    if(s[j] == s[i])
                        dp[i][j] = dp[i+1][j-1];
                    else{
                        dp[i][j] = 0;
                    }
                }
            }
        }
        for(int i=0; i<s.size(); i++){
            if(dp[0][i]){
                for(int j=i+1; j<n-1; j++){
                    if(dp[i+1][j] && dp[j+1][n-1])
                        return true;
                }
            }
        }
        return false;
    }
};