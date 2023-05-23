//M1
//Creating a new Binary Tree
//Faster than 17.4% (50ms)

class Solution {
public:
    TreeNode* merge(TreeNode* root1, TreeNode* root2){
        if(!root1 and !root2) return NULL;
        int l=0,r=0;
        if(root1) l = root1->val;
        if(root2) r = root2->val;
        TreeNode* ans = new TreeNode(l+r);
        ans->left = merge(root1?root1->left:NULL , root2?root2->left:NULL);
        ans->right = merge(root1?root1->right:NULL , root2?root2->right:NULL);
        return ans;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return merge(root1, root2);
    }
};

//M2
//Editing the existing Binary Tree
//Faster than 5.9% (70ms)

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        
        if(!root1) return root2;
        if(!root2) return root1;
        
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        
        return root1;
        
    }
};