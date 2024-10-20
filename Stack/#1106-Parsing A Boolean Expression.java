//M1
//Using stack
//Faster than 18.89% (17 ms)

class Solution {
    public boolean parseBoolExpr(String s) {
        int n = s.length();
        Boolean res = true;
        Stack<Character> st = new Stack<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c == ',' || c == '(')
                continue;
            else if (c == ')') {
                Boolean hasTrue = false, hasFalse = false;
                while (st.peek() != '!' && st.peek() != '&' && st.peek() != '|') {
                    char topVal = st.peek();
                    st.pop();
                    if (topVal == 'f')
                        hasFalse = true;
                    else
                        hasTrue = true;
                }
                char exp = st.peek();
                st.pop();
                if (exp == '!') {
                    st.push(hasTrue ? 'f' : 't');
                } else if (exp == '|') {
                    st.push(hasTrue ? 't' : 'f');
                } else {
                    st.push(hasFalse ? 'f' : 't');
                }
            } else
                st.push(c);
        }
        return st.peek() == 't';
    }
}
