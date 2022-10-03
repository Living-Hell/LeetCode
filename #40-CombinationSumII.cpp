//M1
//Recusrion & Backtracking
// Faster than 28% (17ms)

class Solution {
public:
    void combination(vector<int> candidates, int target, vector<vector<int>> &res, vector<int> &combo, 
                     int currIndex, int n){
        
        if(target == 0){
            res.push_back(combo);
            return;
        }
        
        for(int i=currIndex; i<n; i++){
            
            if(target<candidates[i]) break; 
            
            combo.push_back(candidates[i]);
            
            combination(candidates, target-candidates[i], res, combo, i+1, n);
            
            while(i<n-1 && candidates[i] == candidates[i+1]) i++;
            
            combo.pop_back();
        }
        
    }    
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
        
        int n = candidates.size();
        vector<int> combo;
        vector<vector<int>> res;
        
        combination(candidates, target,res, combo, 0, n);
        
        return res;
        
    }
};