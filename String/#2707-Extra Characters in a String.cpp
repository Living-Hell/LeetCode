//M1
//Using recursion + memoisation
//Faster than 71.45% (97 ms)

class Solution {
public:
    int dp[51];
    int solve(string& s, unordered_set<string>& st, int ind) {
        if (ind >= s.size())
            return 0;

        if (dp[ind] != -1)
            return dp[ind];
        int res = s.size();

        string curr = "";
        for (int i = ind; i < s.size(); i++) {
            curr.push_back(s[i]);
            if (st.count(curr))
                res = min(res, solve(s, st, i + 1));
            else
                res = min({res, (int)curr.size() + solve(s, st, i + 1)});
        }

        return dp[ind] = res;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        memset(dp, -1, sizeof(dp));
        unordered_set<string> st(dictionary.begin(), dictionary.end());
        return solve(s, st, 0);
    }
};
