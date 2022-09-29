//Using Recursion & Backtracking
// Faster Than 30.5% (43ms)

class Solution {
public:
    void combination(vector<int> candidates, int target, vector<int> &combo, 
                     vector<vector<int>> &ans, int currSum, int currIndex){
        
        if(currSum > target) return;
        
        if(currSum == target){
            ans.push_back(combo);
            return;
        }
        
        for(int i=currIndex; i<candidates.size(); i++){
            combo.push_back(candidates[i]);
            currSum += candidates[i];
            combination(candidates, target, combo, ans, currSum, i);
            combo.pop_back();
            currSum -= candidates[i];
        }
        
    }    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int> combo;
        vector<vector<int>> ans;
        
        combination(candidates, target, combo, ans, 0, 0);
        
        return ans;
        
    }
};