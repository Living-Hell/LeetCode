// M1
// Using recursion and backtracking
// Faster than 100% (0ms)

class Solution
{
public:
    void helper(vector<int> &nums, vector<vector<int>> &ans, vector<int> &temp, int ind)
    {
        ans.push_back(temp);
        for (int i = ind; i < nums.size(); i++)
        {
            if (i > ind and nums[i] == nums[i - 1])
                continue;
            temp.push_back(nums[i]);
            helper(nums, ans, temp, i + 1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        helper(nums, ans, temp, 0);
        return ans;
    }
};