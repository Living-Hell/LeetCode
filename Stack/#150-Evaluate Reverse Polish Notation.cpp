// M1
// Using stack
// faster than 82.69% (7ms)

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "+" or tokens[i] == "-" or tokens[i] == "*" or tokens[i] == "/")
            {
                int first = st.top();
                st.pop();
                int second = st.top();
                st.pop();
                if (tokens[i] == "+")
                    st.push(second + first);
                else if (tokens[i] == "-")
                    st.push(second - first);
                else if (tokens[i] == "*")
                    st.push(second * first);
                else
                    st.push(second / first);
                cout << st.top() << " ";
            }
            else
                st.push(stoi(tokens[i]));
        }
        return st.top();
    }
};