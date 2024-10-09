//M1
//Using Stack
//Faster than 100% (0ms)

class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                st.push(s[i]);
                continue;
            }
            if (st.top() == '(' && s[i] == ')')
                st.pop();
            else
                st.push(s[i]);
        }
        return st.size();
    }
};
