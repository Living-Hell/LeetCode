// M1
// Using stacks
// Faster than 12.5% (182ms)

class Solution
{
public:
    long long maximumSumOfHeights(vector<int> &ht)
    {
        long long ans = 0, sum = 0;
        int n = ht.size();

        vector<long long> left(n), right(n);
        stack<long long> st;
        st.push(-1);

        for (int i = 0; i < n; i++)
        {
            while (st.size() > 1 and ht[st.top()] >= ht[i])
                st.pop();
            if (st.size() == 1)
                sum = 0;
            else
                sum = left[st.top()];

            sum += (i - st.top()) * 1LL * ht[i];
            left[i] = sum;
            st.push(i);
        }

        while (st.size())
            st.pop();
        st.push(n);
        sum = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            while (st.size() > 1 and ht[st.top()] >= ht[i])
                st.pop();
            if (st.size() == 1)
                sum = 0;
            else
                sum = right[st.top()];

            sum += (st.top() - i) * 1LL * ht[i];
            right[i] = sum;
            st.push(i);
        }

        for (int i = 0; i < n; i++)
            ans = max(ans, 1LL * (left[i] + right[i] - ht[i]));
        return ans;
    }
};