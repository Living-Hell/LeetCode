//M1
//Recursion & DFS using hashmap
//Faster than 69% (28ms)

class Solution {
public:
    int solve(TreeNode* root, unordered_map<int,int> &mp){
        
        if(!root) return 0;
        
        int sum = root->val + solve(root->left, mp) + solve(root->right, mp);
        
        mp[sum]++;
        
        return sum;
        
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        
        unordered_map<int,int> mp;
        
        solve(root,mp);
        
        int maxfreq = 0;
        vector<int> ans;
        
        for(auto i:mp)
            maxfreq = max(maxfreq, i.second);
        
        for(auto i:mp)
            if(i.second == maxfreq)
                ans.push_back(i.first);
        
        return ans;
        
    }
};