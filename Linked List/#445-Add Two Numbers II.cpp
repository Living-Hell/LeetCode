// M1
// Using stack
// Faster than 96.9% (12ms)

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
    ListNode *solve(stack<ListNode *> st1, stack<ListNode *> st2, ListNode *l1)
    {
        int carry = 0;
        while (!st2.empty())
        {
            int sum = st1.top()->val + st2.top()->val + carry;
            int val = sum % 10;
            carry = sum / 10;
            st1.top()->val = val;
            st1.pop();
            st2.pop();
        }
        while (!st1.empty() and carry > 0)
        {
            int sum = st1.top()->val + carry;
            int val = sum % 10;
            carry = sum / 10;
            st1.top()->val = val;
            st1.pop();
        }
        if (carry > 0)
        {
            ListNode *temp = new ListNode(carry);
            temp->next = l1;
            return temp;
        }
        return l1;
    }
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        stack<ListNode *> st1, st2;
        ListNode *t1 = l1;
        ListNode *t2 = l2;
        while (t1)
            st1.push(t1), t1 = t1->next;
        while (t2)
            st2.push(t2), t2 = t2->next;
        if (st1.size() > st2.size())
            return solve(st1, st2, l1);
        else
            return solve(st2, st1, l2);
    }
};