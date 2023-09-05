// M1
// Using Inorde Traversal
// Faster than 87.26% (20 ms)

class Solution
{
public:
    TreeNode *first = NULL;
    TreeNode *second = NULL;
    TreeNode *prev = NULL;
    void solve(TreeNode *root)
    {
        if (!root)
            return;
        solve(root->left);
        if (prev)
        {
            if (prev->val > root->val)
            {
                if (!first)
                    first = prev;
                second = root;
            }
        }
        prev = root;
        solve(root->right);
    }
    void recoverTree(TreeNode *root)
    {
        solve(root);
        swap(first->val, second->val);
    }
};