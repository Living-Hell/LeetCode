//M1
//Using recursion and memoisation
//Faster than 79.3% (42ms)

class Solution {
public:
    int dp[100001];
    bool solve(int n) {
        if (n == 1)
            return 1;
        if (n == 2)
            return 0;

        if (dp[n] != -1)
            return dp[n];

        for (int i = 1; i * i <= n; i++) {
            if (i * i <= n) {
                if (!solve(n - i * i))
                    return dp[n] = 1;
            }
        }
        return dp[n] = 0;
    }
    bool winnerSquareGame(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n);
    }
};
