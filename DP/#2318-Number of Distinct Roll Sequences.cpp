//M1
//Using DP (recursion + memoisation)
//Faster than 80.29% (79ms)

class Solution {
public:
    int dp[10001][8][8];
    int solve(int n, int lastToLast, int last) {
        if (n == 0)
            return 1;
        if (dp[n][lastToLast][last] != -1)
            return dp[n][lastToLast][last];
        int res = 0;
        for (int i = 1; i <= 6; i++) {
            if (__gcd(last, i) == 1 and last != i and lastToLast != i) {
                res = (res + solve(n - 1, last, i)) % 1000000007;
            }
        }
        return dp[n][lastToLast][last] = res;
    }
    int distinctSequences(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(n, 7, 7);
    }
};
