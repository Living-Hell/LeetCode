// M1
// Using brute force and iterating through the linked list
// Faster than 66.01% (31ms)

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
    int numComponents(ListNode *head, vector<int> &nums)
    {
        ListNode *temp = head;
        bool prev = 0, curr;
        int ans = 0;
        unordered_set<int> st(nums.begin(), nums.end());

        while (temp)
        {
            curr = st.count(temp->val);
            if (!prev and curr)
                ans++;
            prev = curr;
            temp = temp->next;
        }

        return ans;
    }
};