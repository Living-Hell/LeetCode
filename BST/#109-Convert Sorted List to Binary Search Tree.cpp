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

// M2
// Using recursion and slow-fast pointers
// Faster than 49.56% (20 ms)

class Solution
{
public:
    ListNode *midVal(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        ListNode *prev = head;

        while (fast and fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if (prev)
            prev->next = NULL;
        return slow;
    }
    TreeNode *sortedListToBST(ListNode *head)
    {
        if (!head)
            return NULL;

        ListNode *mid = midVal(head);

        TreeNode *node = new TreeNode(mid->val);

        if (head == mid)
            return node;

        node->left = sortedListToBST(head);
        node->right = sortedListToBST(mid->next);

        return node;
    }
};