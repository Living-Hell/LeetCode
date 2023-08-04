// M1
// Using DFS
// Faster than 96.22% (392ms)

class Solution
{
public:
    vector<int> restoreArray(vector<vector<int>> &aP)
    {
        int n = aP.size();
        unordered_map<int, vector<int>> mp;
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            int f = aP[i][0], s = aP[i][1];
            mp[s].push_back(f);
            mp[f].push_back(s);
        }

        for (auto i : mp)
        {
            if (i.second.size() == 1)
            {
                ans.push_back(i.first);
                break;
            }
        }

        int start = ans[0];
        stack<int> st;
        st.push(start);
        unordered_set<int> vis;
        vis.insert(start);

        while (!st.empty())
        {
            int top = st.top();
            st.pop();
            for (int i : mp[top])
            {
                if (!vis.count(i))
                {
                    st.push(i);
                    ans.push_back(i);
                    vis.insert(i);
                }
            }
        }
        return ans;
    }
};