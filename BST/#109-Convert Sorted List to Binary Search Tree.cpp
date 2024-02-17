// M1
// Using vector and recursion
// Faster than 6.74% (220ms)

class Solution
{
public:
    TreeNode *toBST(vector<int> v, int st, int end)
    {
        if (st > end)
            return NULL;

        int mid = st + (end - st) / 2;

        TreeNode *node = new TreeNode(v[mid]);

        node->left = toBST(v, st, mid - 1);
        node->right = toBST(v, mid + 1, end);

        return node;
    }
    TreeNode *sortedListToBST(ListNode *head)
    {
        vector<int> v;
        ListNode *temp = head;

        while (temp)
        {
            v.push_back(temp->val);
            temp = temp->next;
        }

        return toBST(v, 0, v.size() - 1);
    }
};