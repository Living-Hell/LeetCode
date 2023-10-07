// M1
// Using monotonic stack
// Faster than 100% (0ms)

class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        vector<bool> vis(26, 0);
        vector<int> freq(26, 0);
        stack<int> st;
        string ans;
        int n = s.size();
        for (char c : s)
            freq[c - 'a']++;
        for (int i = 0; i < n; i++)
        {
            int c = s[i] - 'a';
            if (vis[c])
            {
                freq[c]--;
                continue;
            }
            while (!st.empty() and st.top() >= c and freq[st.top()] > 0)
            {
                vis[st.top()] = 0;
                st.pop();
            }
            st.push(c);
            freq[c]--;
            vis[c] = 1;
        }
        while (!st.empty())
        {
            ans.push_back(st.top() + 'a');
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};