//M1
//Using DP (recursion + memoisation)
//Faster than 32.54% (8ms)

class Solution {
public:
    int dp[102][102];
    bool helper(string s1, string s2, string s3, int i, int j, int k) {
        if (i == s1.size() and j == s2.size() and k == s3.size())
            return 1;
        if (i < s1.size() and j < s2.size() and dp[i][j] != -1)
            return dp[i][j];
        if (i < s1.size() and j < s2.size() and s1[i] == s3[k] and
            s2[j] == s3[k])
            return dp[i][j] = helper(s1, s2, s3, i + 1, j, k + 1) ||
                              helper(s1, s2, s3, i, j + 1, k + 1);
        if (i < s1.size() and s1[i] == s3[k])
            return dp[i][j] = helper(s1, s2, s3, i + 1, j, k + 1);
        if (j < s2.size() and s2[j] == s3[k])
            return dp[i][j] = helper(s1, s2, s3, i, j + 1, k + 1);
        return dp[i][j] = false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if (!s1.size())
            return s2 == s3;
        if (!s2.size())
            return s1 == s3;
        memset(dp, -1, sizeof(dp));
        return helper(s1, s2, s3, 0, 0, 0);
    }
};
