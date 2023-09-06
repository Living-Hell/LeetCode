// M1
// Using Backtracking
// Faster than 10% (0ms)

class Solution
{
public:
    void solve(int k, int n, vector<vector<int>> &ans, vector<int> &curr, vector<bool> &vis, int st)
    {
        if (k == 0 and n == 0)
        {
            ans.push_back(curr);
            return;
        }
        if (k < 0 or n < 0)
            return;
        for (int i = st; i <= 9; i++)
        {
            if (!vis[i])
            {
                vis[i] = 1;
                curr.push_back(i);
                solve(k - 1, n - i, ans, curr, vis, i + 1);
                vis[i] = 0;
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> curr;
        vector<bool> vis(10, 0);
        solve(k, n, ans, curr, vis, 1);
        return ans;
    }
};