// M1
// Using while loop
// Faster than 75.07% (39ms)

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
    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        ListNode *temp = head;
        int prev = head->val;
        while (temp->next)
        {
            ListNode *temp1 = temp->next;
            int gcd = __gcd(prev, temp1->val);
            ListNode *nNode = new ListNode(gcd);
            temp->next = nNode;
            nNode->next = temp1;
            temp = temp1;
            prev = temp->val;
        }
        return head;
    }
};