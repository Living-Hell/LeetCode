//M1
//Using DP (recursion + memoisation)
//Faster than 49.62% (4ms)

class Solution {
public:
    vector<int> pref = {0};
    int dp[31][31];
    int solve(vector<int>& stones, int k, int st, int end) {
        if (st >= end)
            return 0;
        if (dp[st][end] != -1)
            return dp[st][end];

        int res = INT_MAX;
        for (int i = st; i < end; i += k - 1) {
            res = min(res,
                      solve(stones, k, st, i) + solve(stones, k, i + 1, end));
        }
        if ((end - st) % (k - 1) == 0)
            res += pref[end + 1] - pref[st];

        return dp[st][end] = res;
    }

    int mergeStones(vector<int>& stones, int k) {
        if ((stones.size() - k) % (k - 1) != 0)
            return -1;
        for (int& i : stones)
            pref.push_back(pref.back() + i);
        memset(dp, -1, sizeof(dp));
        return solve(stones, k, 0, stones.size() - 1);
    }
};
