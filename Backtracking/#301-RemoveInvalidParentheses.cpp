// M1
// Using Recursion and Backtracking
// Faster than 55.58% (185ms)

class Solution
{
public:
    set<pair<int, string>> ipr;
    void invalidParenthesesRemover(string s, unordered_set<string> &ans, int ind, int count)
    {
        pair<int, string> x = make_pair(ind, s);
        if (ipr.find(x) != ipr.end())
            return;
        if (ind == s.size())
        {
            if (count == 0)
                ans.insert(s);
            return;
        }
        if (s[ind] == '(' or s[ind] == ')')
        {
            string temp = s;
            temp.erase(ind, 1);
            invalidParenthesesRemover(temp, ans, ind, count);
        }
        if (s[ind] == '(')
            count++;
        if (s[ind] == ')')
            count--;
        if (count < 0)
            return;
        ipr.insert(x);
        invalidParenthesesRemover(s, ans, ind + 1, count);
    }
    vector<string> removeInvalidParentheses(string s)
    {
        unordered_set<string> ans;
        invalidParenthesesRemover(s, ans, 0, 0);
        int mx = 0;
        for (string i : ans)
        {
            int sz = i.size();
            mx = max(mx, sz);
        }
        vector<string> ret;
        for (string i : ans)
            if (i.size() == mx)
                ret.push_back(i);
        return ret;
    }
};