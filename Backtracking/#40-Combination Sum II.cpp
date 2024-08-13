//M1
//Using backtracking
//Faster than 100% (0ms)

class Solution {
public:
    void solve(vector<int>& candidates, int target, int ind, vector<int>& temp,
               vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(temp);
            return;
        }
        for (int i = ind; i < candidates.size(); i++) {
            if (candidates[i] > target)
                return;
            temp.push_back(candidates[i]);
            solve(candidates, target - candidates[i], i + 1, temp, res);
            while (i < candidates.size() - 1 and
                   candidates[i] == candidates[i + 1])
                i++;
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> temp;
        solve(candidates, target, 0, temp, res);
        return res;
    }
};
