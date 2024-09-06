//M1
//Using recursion and memoisation
//Faster than 89.01% (335 ms)

class Solution {
public:
    int dp[502][502];
    int solve(vector<int>& pref, int st, int end) {
        if (st >= end)
            return 0;
        int res = 0;

        if (dp[st][end] != -1)
            return dp[st][end];

        for (int i = st; i < end; i++) {
            int firstHalf = pref[i] - pref[st - 1];
            int secHalf = pref[end] - pref[i];
            if (firstHalf >= secHalf) {
                res = max(res, secHalf + solve(pref, i + 1, end));
            }
            if (firstHalf <= secHalf) {
                res = max(res, firstHalf + solve(pref, st, i));
            }
        }
        return dp[st][end] = res;
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> pref(n + 1);
        pref[0] = 0;
        for (int i = 1; i <= n; i++) {
            pref[i] = pref[i - 1] + stoneValue[i - 1];
        }
        memset(dp, -1, sizeof(dp));
        return solve(pref, 1, n);
    }
};
