// M1
// Using while loop and pointers
// Faster than 58.65% (28ms)

class Solution
{
public:
    ListNode *insertionSortList(ListNode *head)
    {
        if (!head)
            return head;

        ListNode *node = new ListNode(-5001);
        ListNode *curr = head;

        while (curr)
        {
            ListNode *temp = curr;
            ListNode *root = node, *prev;
            while (root and root->val < temp->val)
            {
                prev = root;
                root = root->next;
            }
            prev->next = temp;
            curr = curr->next;
            temp->next = root;
        }
        return node->next;
    }
};