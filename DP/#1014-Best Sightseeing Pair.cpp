// M1
// Using Stack - Monotonic stack
// Faster than 7.11% (73ms)
class Solution
{
public:
    int maxScoreSightseeingPair(vector<int> &values)
    {
        int n = values.size(), ans = 0;
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while ((!st.empty() and values[st.top()] <= values[i]))
            {
                int top = st.top();
                st.pop();
                ans = max(ans, values[top] + values[i] + top - i);
            }
            if (!st.empty())
            {
                ans = max(ans, values[st.top()] + values[i] + st.top() - i);
            }
            st.push(i);
        }
        return ans;
    }
};

// M2
// Using DP
// Faster than 38.3% (45ms)
class Solution
{
public:
    int maxScoreSightseeingPair(vector<int> &values)
    {
        int n = values.size(), ans = 0, curr = values[0];
        for (int i = 1; i < n; i++)
        {
            ans = max(ans, curr + values[i] - i);
            curr = max(curr, values[i] + i);
        }
        return ans;
    }
};