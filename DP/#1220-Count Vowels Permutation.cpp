//M1
//Using recursion + memoisation
//Faster than 7.62% (1008ms)

class Solution {
public:
    int dp[20001][27];
    unordered_map<char,vector<char>> mp;
    int mod = 1e9+7;

    int solve(int n, int len, char last){
        if(len == n) return 1;

        if(dp[len][last-'a'] != -1) return dp[len][last-'a'];

        int res = 0;

        for(char &c : mp[last])
            res = (res + solve(n,len+1,c))%mod;
        
        return dp[len][last-'a'] = res;
    }
    int countVowelPermutation(int n) {
        mp['a']={'e'};
        mp['e']={'a','i'};
        mp['i']={'a','e','o','u'};
        mp['o']={'i','u'};
        mp['u']={'a'};
        mp['s']={'a','e','i','o','u'};

        memset(dp,-1,sizeof(dp));

        return solve(n,0,'s');
    }
};
