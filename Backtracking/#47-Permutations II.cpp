// M1
// Backtracking
// Faster than 36.87% (51 ms)

class Solution
{
public:
    void helper(vector<int> &nums, set<vector<int>> &ans, vector<int> &temp, vector<bool> &vis)
    {
        if (temp.size() == nums.size())
        {
            ans.insert(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (!vis[i])
            {
                vis[i] = 1;
                temp.push_back(nums[i]);
                helper(nums, ans, temp, vis);
                temp.pop_back();
                vis[i] = 0;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        set<vector<int>> ans;
        vector<int> temp;
        vector<bool> vis(nums.size(), 0);
        helper(nums, ans, temp, vis);
        vector<vector<int>> ret(ans.begin(), ans.end());
        return ret;
    }
};