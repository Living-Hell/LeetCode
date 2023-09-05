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

// M2
// Using Morris Traversal O(1) space
// Faster than 91.13% (19ms)

class Solution
{
public:
    TreeNode *first = NULL;
    TreeNode *second = NULL;
    TreeNode *prev = NULL;
    void check(TreeNode *curr)
    {
        if (prev != NULL and (curr->val < prev->val))
        {
            if (!first)
                first = prev;
            second = curr;
        }
        prev = curr;
    }
    void recoverTree(TreeNode *root)
    {
        if (!root)
            return;
        TreeNode *curr = root;
        while (curr != NULL)
        {
            if (curr->left == NULL)
            {
                check(curr);
                curr = curr->right;
            }
            else
            {
                TreeNode *pred = curr->left;
                while ((pred->right != NULL) and (pred->right != curr))
                    pred = pred->right;
                if (pred->right == NULL)
                {
                    pred->right = curr;
                    curr = curr->left;
                }
                else
                {
                    pred->right = NULL;
                    check(curr);
                    curr = curr->right;
                }
            }
        }
        swap(first->val, second->val);
    }
};