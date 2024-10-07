//M1
//Using Stack 
//Faster than 89.38% (3ms)

class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for (char& c : s) {
            if (c == 'B' or c == 'D') {
                if (st.size() and ((st.top() == 'A' and c == 'B') or
                    (st.top() == 'C' and c == 'D'))) {
                    st.pop();
                    continue;
                }
            }
            st.push(c);
        }
        return st.size();
    }
};
