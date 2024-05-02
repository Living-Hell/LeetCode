// M1
// Using Brute Force
// Faster than 24.41% (8ms)

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
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        vector<ListNode *> res;
        int sz = 0;
        ListNode *temp = head;
        while (temp)
            temp = temp->next, sz++;
        int n1 = sz / k;
        int n2 = sz % k;
        int rem = k - n2;
        ListNode *root = head;
        while (n2--)
        {
            res.push_back(root);
            int t1 = 0;
            while (t1 < n1 and root)
                root = root->next, t1++;
            ListNode *end = root;
            if (root)
                root = root->next;
            if (end)
                end->next = NULL;
        }
        while (rem--)
        {
            if (root)
                res.push_back(root);
            else
                res.push_back({});
            int t1 = 0;
            while (t1 < n1 - 1 and root)
                root = root->next, t1++;
            ListNode *end = root;
            if (root)
                root = root->next;
            if (end)
                end->next = NULL;
        }
        return res;
    }
};