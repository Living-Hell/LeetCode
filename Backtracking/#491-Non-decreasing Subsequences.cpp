// M1
// Using backtracking and set
// Faster than 58.46% (63ms)

class Solution
{
public:
    void solve(vector<int> &nums, set<vector<int>> &ans, vector<int> &curr, int ind)
    {
        if (ind == nums.size())
        {
            if (curr.size() >= 2)
                ans.insert(curr);
            return;
        }

        if (curr.size() == 0 or nums[ind] >= curr.back())
        {
            curr.push_back(nums[ind]);
            solve(nums, ans, curr, ind + 1);
            curr.pop_back();
        }
        solve(nums, ans, curr, ind + 1);
    }
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        set<vector<int>> ans;
        vector<int> temp;
        solve(nums, ans, temp, 0);
        return vector(ans.begin(), ans.end());
    }
};