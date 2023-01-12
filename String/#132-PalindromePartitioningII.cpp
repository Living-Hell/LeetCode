//M1
//Using Dp
//Faster than 71.24%(86ms)

class Solution {
public:
    int minCut(string str){
        int n = str.size();
        if(n==1) return 0;
        
        vector<vector<int>> dp(n, vector<int> (n,0));
        
        for(int gap=0; gap<n; gap++){
            for(int i=0, j=gap; j<n; j++, i++){
                if(gap==0) 
                    dp[i][j]=1;
                else if(gap==1){
                    if(str[j] == str[j-1])
                        dp[i][j] = 1;
                    else
                        dp[i][j]=0;
                }
                else{
                    if(str[j] == str[i])
                        dp[i][j] = dp[i+1][j-1];
                    else{
                        dp[i][j] = 0;
                    }
                }
            }
        }
        
        vector<int> cuts(n);
        cuts[0] = 0;
        
        if(str[1] != str[0]) cuts[1] = 1;
        
        for(int i=2; i<n; i++){
            if(dp[0][i]){
                cuts[i] = 0;
                continue;
            }
            int ans=INT_MAX;
            for(int j=0; j<=i; j++){
                if(dp[j][i]){
                    ans = min(ans,1 + cuts[j-1]);
                }
            }
            cuts[i] = ans;
        }
        return cuts[n-1];
    }
};