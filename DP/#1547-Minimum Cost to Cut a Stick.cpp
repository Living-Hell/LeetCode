//M1
//Using DP (recursion + memoisation)
//Faster than 54.18% (34ms)

class Solution {
public:
    int dp[102][102];
    int solve(int n, vector<int>& cuts, int st, int end) {
        if (end - st <= 1)
            return 0;

        int res = INT_MAX;
        if (dp[st][end] != -1)
            return dp[st][end];
        for (int i = st + 1; i < end; i++) {
            res = min(res, cuts[end] - cuts[st] + solve(n, cuts, st, i) +
                               solve(n, cuts, i, end));
        }
        return dp[st][end] = res;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        memset(dp, -1, sizeof(dp));
        return solve(n, cuts, 0, cuts.size() - 1);
    }
};
