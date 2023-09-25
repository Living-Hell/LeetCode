// M1
// Using backtracking
// Faster than 90.59% (3ms)

class Solution
{
public:
    void solve(string s, int i, vector<string> &ans)
    {
        if (i == s.size())
        {
            ans.push_back(s);
            return;
        }
        char c = s[i];
        if (isalpha(s[i]))
        {
            s[i] = islower(c) ? toupper(c) : tolower(c);
            solve(s, i + 1, ans);
            s[i] = c;
        }
        solve(s, i + 1, ans);
    }
    vector<string> letterCasePermutation(string s)
    {
        vector<string> ans;
        solve(s, 0, ans);
        return ans;
    }
};