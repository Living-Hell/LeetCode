// M1
// Using Recursion and Backtracking
// Faster than 85% (55ms)

class Solution
{
public:
    set<pair<int, string>> ipr;
    int getMin(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                st.push(s[i]);
            else if (s[i] == ')')
            {
                if (st.size() > 0 and st.top() == '(')
                    st.pop();
                else
                    st.push(s[i]);
            }
        }
        return st.size();
    }
    void invalidParenthesesRemover(string s, unordered_set<string> &ans, int ind, int count, int mra)
    {
        if (mra < 0)
            return;
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
            invalidParenthesesRemover(temp, ans, ind, count, mra - 1);
        }
        if (s[ind] == '(')
            count++;
        if (s[ind] == ')')
            count--;
        if (count < 0)
            return;
        ipr.insert(x);
        invalidParenthesesRemover(s, ans, ind + 1, count, mra);
    }
    vector<string> removeInvalidParentheses(string s)
    {
        unordered_set<string> ans;
        int mra = getMin(s);
        invalidParenthesesRemover(s, ans, 0, 0, mra);
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