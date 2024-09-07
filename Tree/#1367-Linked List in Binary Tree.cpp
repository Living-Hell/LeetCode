//M1
//Using recursion
//Faster than 60.41% (24ms)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool solve(ListNode* head, TreeNode* root) {
        if (!head)
            return 1;
        if (!root)
            return 0;
        if (head->val == root->val && solve(head->next, root->left))
            return 1;
        if (head->val == root->val && solve(head->next, root->right))
            return 1;
        return 0;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!root)
            return 0;
        if (solve(head, root) or isSubPath(head, root->left) or
            isSubPath(head, root->right))
            return 1;
        return 0;
    }
};
