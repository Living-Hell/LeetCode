//M1
//Using DP, recursion + memoisation
//Faster than 6.31% (2432ms)

class Solution {
public:
    int dp[1001][1001];
    int solve(string s1, string s2, int i, int j) {
        if (i == s1.size() or j == s2.size())
            return 0;

        int res = 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i] == s2[j])
            res = 1 + solve(s1, s2, i + 1, j + 1);
        else
            res = max(solve(s1, s2, i + 1, j), solve(s1, s2, i, j + 1));

        return dp[i][j] = res;
    }
    string shortestCommonSupersequence(string str1, string str2) {
        memset(dp, -1, sizeof(dp));
        solve(str1, str2, 0, 0);
        string ans = "";
        int i = 0, j = 0;
        while (i < str1.size() and j < str2.size()) {
            if (str1[i] == str2[j]) {
                ans.push_back(str1[i]);
                i++, j++;
            } else if (dp[i + 1][j] < dp[i][j + 1]) {
                ans.push_back(str2[j]);
                j++;
            } else {
                ans.push_back(str1[i]);
                i++;
            }
        }
        while (i < str1.size())
            ans.push_back(str1[i++]);
        while (j < str2.size())
            ans.push_back(str2[j++]);
        return ans;
    }
};
