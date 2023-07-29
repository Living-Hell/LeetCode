// M1
// Using 2 stacks
// Faster than 100% (0ms)

class Solution
{
public:
    bool checkValidString(string s)
    {
        stack<int> hash;
        int n = s.size();
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                st.push(i);
            else if (s[i] == ')')
            {
                if (!st.empty())
                    st.pop();
                else if (hash.size() == 0)
                    return 0;
                else
                    hash.pop();
            }
            else
                hash.push(i);
        }
        while (!st.empty() and !hash.empty())
        {
            if (hash.top() < st.top())
            {
                return 0;
            }
            hash.pop();
            st.pop();
        }
        return st.empty();
    }
};