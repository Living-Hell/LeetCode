//M1
//Recursion & Backtracking 
//Faster than 16.67%% (610ms)

class Solution {
public:
    void combination(vector<int> candidates, vector<int> &combo, vector<vector<int>> &res, int currIndex, int k){
        
        if(combo.size() == k){
            res.push_back(combo);
            return;
        }
        
        for(int i=currIndex; i<candidates.size(); i++){
            combo.push_back(candidates[i]);
            combination(candidates,combo, res, i+1,k);
            combo.pop_back();
        }
        
    }    
    
    vector<vector<int>> combine(int n, int k) {
        
        vector<int> candidates(n);
        for(int i=0; i<n; i++) candidates[i] = i+1;
        vector<int> combo;
        vector<vector<int>> res;
        
        combination(candidates, combo, res, 0, k);
        
        return res;
        
    }
};