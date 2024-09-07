//M1
//Using Recursion + Memoisation
//Faster than 27.19% (133ms)

class Solution {
public:
    int dp[100003][2];
    int solve(int n, vector<int> &pref, int ind,
              bool isAlice) {
        if (ind == n)
            return 0;
        if (ind == n - 1)
            return isAlice ? pref[n - 1] : -pref[n - 1];

        if(dp[ind][isAlice] != -1) return dp[ind][isAlice];

        int res = isAlice
                  ? max(solve(n, pref, ind + 1, isAlice),
                        solve(n, pref, ind + 1, !isAlice) + pref[ind])
                  : min(solve(n, pref, ind + 1, isAlice),
                        solve(n, pref, ind + 1, !isAlice) - pref[ind]);
        return dp[ind][isAlice] = res;
    }
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> pref(n + 1);
        pref[0] = 0;
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + stones[i-1];
        }
        memset(dp,-1, sizeof(dp));
        return solve(n+1, pref, 2, 1);
    }
};
