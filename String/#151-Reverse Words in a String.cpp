// M1
// Using stack
// Faster than 86.35% (3ms)

class Solution
{
public:
    string reverseWords(string s)
    {
        stack<string> st;
        string temp;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                if (temp.size())
                    st.push(temp);
                temp = "";
            }
            else
                temp += s[i];
        }
        if (temp.size())
            st.push(temp);
        ;
        string res = "";
        while (!st.empty())
            res += st.top() + " ", st.pop();
        res.pop_back();
        return res;
    }
};