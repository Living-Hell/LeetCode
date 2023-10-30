// M1
// Using pointers
// Faster than 92.68% (7 ms)

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
class Solution
{
public:
    ListNode *kthNode(ListNode *head, int k)
    {
        while (head and k--)
            head = head->next;
        return head;
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *root = new ListNode(-1, head);
        ListNode *gprev = root;
        while (1)
        {
            ListNode *kth = kthNode(gprev, k);
            if (!kth)
                break;

            ListNode *gnext = kth->next;
            ListNode *curr = gprev->next, *prev = kth->next;

            while (curr != gnext)
            {
                ListNode *temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            ListNode *temp = gprev->next;
            gprev->next = kth;
            gprev = temp;
        }
        return root->next;
    }
};