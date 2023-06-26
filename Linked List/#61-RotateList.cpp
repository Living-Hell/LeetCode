//M1
//Using intuition
//Faster than 96.68% (3ms)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head or !head->next) return head;
        ListNode* temp = head;
        int count=1;
        while(temp->next){ 
            temp = temp->next;
            count++;
        }
        k = k%count;
        k = count-k;
        temp->next = head;
        temp = head;
        while(--k) temp = temp->next;
        head = temp->next;
        temp->next = NULL;
        return head;
    }
};