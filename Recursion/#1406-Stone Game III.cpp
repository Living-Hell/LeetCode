//M1
//Using recursion and memoisation
//Faster than 31.54% (190ms)

class Solution {
public:
    int dp[50001][3];
    int solve(vector<int>& stones, int n, int i, bool isAlice) {
        if (i >= stones.size())
            return 0;

        if (dp[i][isAlice] != -1)
            return dp[i][isAlice];

        int res = isAlice ? INT_MIN : INT_MAX, rocks = 0;
        int bound = min(3, n - i);

        for (int ind = 1; ind <= bound; ind++) {
            rocks += stones[i + ind - 1];
            if (isAlice) {
                res = max(res, rocks + solve(stones, n, i + ind, !isAlice));
            } else {
                res = min(res, solve(stones, n, i + ind, !isAlice));
            }
        }
        return dp[i][isAlice] = res;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int tot = 0;

        memset(dp, -1, sizeof(dp));
        int alice = solve(stoneValue, n, 0, 1);
        for (int& i : stoneValue)
            tot += i;
        int bob = tot - alice;

        if (alice == bob)
            return "Tie";
        return alice > bob ? "Alice" : "Bob";
    }
};
