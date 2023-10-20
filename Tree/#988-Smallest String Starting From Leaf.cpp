// M1
// Using Preorder traversal (DFS)
// Faster than 46.31% (11ms)

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
class Solution
{
public:
    void preorder(TreeNode *root, string curr, string &ans)
    {
        if (!root)
            return;

        if (root->left == NULL and root->right == NULL)
        {
            curr.push_back(root->val + 'a');
            reverse(curr.begin(), curr.end());
            if (!ans.size())
                ans = curr;
            else
                ans = min(ans, curr);
            return;
        }

        curr.push_back(root->val + 'a');

        preorder(root->left, curr, ans);
        preorder(root->right, curr, ans);

        curr.pop_back();
    }
    string smallestFromLeaf(TreeNode *root)
    {
        string ans;
        preorder(root, "", ans);
        return ans;
    }
};

//M2
//Using DFS (Preorder traversal)
//