//M1
//Using sets
//Faster than 48.8% (178ms)

class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int n = rolls.size(), i = 0, res = 1;
        unordered_set<int> st;
        while (i < n) {
            if (st.size() == k) {
                res++;
                st.clear();
            }
            st.insert(rolls[i]);
            i++;
        }
        if (st.size() == k) {
            res++;
        }
        return res;
    }
};
