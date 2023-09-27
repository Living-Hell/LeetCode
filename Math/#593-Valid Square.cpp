// M1
// Using maths
// Faster than 14.6% (9ms)

class Solution
{
public:
    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
    {
        if (p1 == p2 or p1 == p3 or p1 == p4 or p2 == p3 or p2 == p4 or p3 == p4)
            return 0;
        int b1 = pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2);
        int b2 = pow(p3[0] - p4[0], 2) + pow(p3[1] - p4[1], 2);
        int b3 = pow(p1[0] - p3[0], 2) + pow(p1[1] - p3[1], 2);
        int b4 = pow(p2[0] - p4[0], 2) + pow(p2[1] - p4[1], 2);
        int b5 = pow(p1[0] - p4[0], 2) + pow(p1[1] - p4[1], 2);
        int b6 = pow(p2[0] - p3[0], 2) + pow(p2[1] - p3[1], 2);
        unordered_set<int> st;
        st.insert(b1);
        st.insert(b2);
        st.insert(b3);
        st.insert(b4);
        st.insert(b5);
        st.insert(b6);
        return st.size() == 2;
    }
};