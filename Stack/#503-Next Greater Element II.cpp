// M1
// Using stack
// Faster than 54.52% (27ms)

class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n);
        for (int i = n - 2; i >= 0; i--)
            st.push(i);
        for (int i = n - 1; i >= 0; i--)
        {
            bool np = 0;
            while (st.size() > 0 and nums[st.top()] <= nums[i])
            {
                if (st.top() == i)
                {
                    ans[i] = -1;
                    np = 1;
                    break;
                }
                st.pop();
            }
            if (!np)
            {
                ans[i] = st.size() ? nums[st.top()] : -1;
                st.push(i);
            }
        }
        return ans;
    }
};