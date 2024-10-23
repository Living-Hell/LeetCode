//M1
//Using recursion, level order traversal and pre-order traversal
//Faster than 99.55% (6ms)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> mp;
    void LOT(TreeNode* root, int lvl){
        if(!root) return;
        if(mp.size() == lvl) 
            mp.push_back(root->val);
        else
            mp[lvl] += root->val;
        LOT(root->left,lvl+1);
        LOT(root->right,lvl+1);
    }
    void preorder(TreeNode* root, int lvl){
        if(!root) return;
        if(root->left == NULL and root->right == NULL) return;
        else if(root->left==NULL) root->right->val = mp[lvl+1]-root->right->val;
        else if(root->right == NULL) root->left->val = mp[lvl+1]-root->left->val;
        else{
            int sub = root->left->val + root->right->val;
            root->left->val = mp[lvl+1] - sub;
            root->right->val = mp[lvl+1] - sub;
        }
        
        preorder(root->left,lvl+1);
        preorder(root->right,lvl+1);
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        LOT(root,0);
        preorder(root,0);
        root->val=0;
        return root;
    }
};
