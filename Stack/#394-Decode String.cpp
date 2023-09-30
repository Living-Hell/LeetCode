// M1
// Using Stack
// Faster than 8.7% (6 ms)

class Solution
{
public:
    string decodeString(string s)
    {
        stack<char> st;
        string ans;
        for (char c : s)
        {
            if (c == ']')
            {
                string temp;
                while (st.top() != '[')
                    temp.push_back(st.top()), st.pop();
                st.pop();
                string cnt;
                while (st.size() and st.top() >= '0' and st.top() <= '9')
                    cnt = st.top() + cnt, st.pop();
                int count = stoi(cnt);
                string res = temp;
                for (int i = 0; i < count - 1; i++)
                    res += temp;
                for (int i = res.size() - 1; i >= 0; i--)
                    st.push(res[i]);
            }
            else
                st.push(c);
        }
        while (!st.empty())
            ans = st.top() + ans, st.pop();
        return ans;
    }
};