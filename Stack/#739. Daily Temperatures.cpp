// M1
// Using stack
// Faster than 98.05% (114 ms)

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temp)
    {
        int n = temp.size();
        vector<int> ans(n);
        stack<int> st;
        st.push(n - 1);
        ans[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            while (!st.empty() and temp[st.top()] <= temp[i])
                st.pop();
            if (st.empty())
                ans[i] = 0;
            else
                ans[i] = st.top() - i;
            st.push(i);
        }
        return ans;
    }
};