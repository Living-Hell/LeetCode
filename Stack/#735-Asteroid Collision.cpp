// M1
// Using Stack
// Faster than 98.52% (4ms)

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> st;
        int n = asteroids.size();
        for (const int &i : asteroids)
        {
            if (st.size() == 0 or i > 0)
                st.push(i);
            else
            {
                while (st.size() > 0 and st.top() > 0 and st.top() < abs(i))
                    st.pop();
                if (st.size() and st.top() == abs(i))
                    st.pop();
                else
                {
                    if (st.size() == 0 or st.top() < 0)
                        st.push(i);
                }
            }
        }
        vector<int> ans;
        while (st.size())
            ans.push_back(st.top()), st.pop();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};71. Simplify Path
