//M1
//Using Dp
//Faster than 41.37% (25ms)

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.size();
        vector<int> dp(n+1, 0);
        dp[0]=1;
        
        for(int i=1; i<=n; i++){
            for(int j=0; j<i; j++){
                string sub1 = s.substr(j,i-j);
                if(find(wordDict.begin(),wordDict.end(),sub1)!=wordDict.end() && dp[j]==1){
                    dp[i]=1;
                }
            }
        }
        return dp[n];        
    }
};