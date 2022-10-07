//M1
//Recursion & Divide and Conquer
//Faster than 45.51% (42ms)

class Solution {
public:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, unordered_map<int,int> &mp,
                   int is, int ie, int ps, int pe){
        
        if(is>ie || ps>pe ) return NULL;
        
        TreeNode* root = new TreeNode(preorder[ps]);
        int index = mp[root->val];
        int numleft = index - is;
        
        root->left = build(preorder, inorder, mp, is, index-1, ps+1, ps + numleft);
        root->right = build(preorder, inorder, mp, index+1, ie, ps + numleft+1, pe);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        if(inorder.size()!= preorder.size()) return NULL;
        
        int n = inorder.size();
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++) mp[inorder[i]] = i;
        
        return build(preorder, inorder, mp, 0, n-1, 0, n-1);
        
    }
};