//M!
//Recursion
//Faster than 65.4% (28ms)

class Solution {
public:    
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, int is, 
                     int ie, int ps, int pe, unordered_map<int,int> &mp){
        
        if(is > ie || ps > pe) return NULL;
        
        TreeNode* ans = new TreeNode(postorder[pe]);
        
        int ind = mp[ans->val];
        int numleft = ind - is;
        
        ans->left = helper(inorder, postorder, is, ind-1, ps, ps + numleft -1 , mp);
        ans->right = helper(inorder, postorder, ind+1, ie, ps + numleft , pe-1, mp);
        
        return ans;
        
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        if(inorder.size() != postorder.size()) return NULL;
        
        unordered_map<int,int> mp;
        int isize = inorder.size(), psize = postorder.size();
        
        for(int i=0; i<isize; i++)
            mp[inorder[i]] = i;
        
        return helper(inorder, postorder, 0, isize-1, 0, psize-1, mp);
        
    }
};