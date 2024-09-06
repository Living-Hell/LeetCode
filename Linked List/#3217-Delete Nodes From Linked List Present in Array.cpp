//M1
//Using intuition and simple while loop
//Faster than 92.29% (404ms)

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
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st(nums.begin(), nums.end());
        ListNode *root = new ListNode(0, head), *temp = root;
        while (temp and temp->next) {
            ListNode* nextNode = temp->next;
            while (nextNode and st.contains(nextNode->val)) {
                nextNode = nextNode->next;
            }
            temp->next = nextNode;
            temp = temp->next;
        }
        return root->next;
    }
};
