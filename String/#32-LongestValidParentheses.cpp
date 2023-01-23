//M1
//Using DP
//Faster than 100%(0ms)

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(); if(n==0) return 0;
        vector<int> dp(n,0);

        for(int i=1; i<n; i++){
            if(s[i] == ')'){
                int prev_left = i-1-dp[i-1];
                if(prev_left>=0 && s[prev_left] == '('){
                    dp[i] = dp[i-1] + 2;
                    if(prev_left>0){
                        dp[i] += dp[prev_left-1];
                    }
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};