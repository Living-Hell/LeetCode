//M1
//Recursion & Backtracking 
//Faster than 5.21%% (33ms)

class Solution {
public:
    void permutations(vector<int> nums, vector<int> curr_perm, vector<vector<int>> &ans, 
                      int n, int curr_idx, unordered_set<int> visited){
        
        if(curr_perm.size() > n) return;
           
        if(curr_perm.size() == n){
            ans.push_back(curr_perm);
            return;
        }
        
        for(int i=0; i<n; i++){
            
            if(visited.find(i) != visited.end()) continue;
            curr_perm.push_back(nums[i]);
            visited.insert(i);
            permutations(nums,curr_perm,ans,n,i,visited);
            curr_perm.pop_back();
            visited.erase(i);
            
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> curr_perm;
        vector<vector<int>> ans;
        unordered_set<int> visited;
        
        permutations(nums, curr_perm, ans, n, -1, visited);
        
        return ans;
    }
};