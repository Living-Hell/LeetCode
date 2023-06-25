//M1
//Using Stacks
//Faster than 71.93% (36ms)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* first, ListNode* second) {
        ListNode* t1 = first; ListNode* t2 = second;
        queue<ListNode*> st1, st2;
        while(t1){
            st1.push(t1);
            t1 = t1->next;
        }
        while(t2){
            st2.push(t2);
            t2 = t2->next;
        }
        int carry=0;
        while(!st1.empty() and !st2.empty()){
            ListNode* top1 = st1.front(); st1.pop();
            ListNode* top2 = st2.front(); st2.pop();
            int sum = top1->val + top2->val + carry;
            if(sum>9){
                carry = 1;
                sum %= 10;
            }
            else carry=0;
            top1->val = sum; top2->val = sum;
        }
        if(carry){
            if(st1.empty() and st2.empty()){
                ListNode* t = new ListNode(1);
                ListNode* temp = first;
                while(temp->next) temp = temp->next;
                temp->next = t;
                return first;
            }
            if(st1.empty()){
                swap(st1,st2);
                swap(first,second);
            }
            ListNode* top = st1.front(); st1.pop();
            if(top->val<9) top->val++;
            else{
                top->val = 0;
                while(!st1.empty() and st1.front()->val == 9){
                    st1.front()->val = 0;
                    st1.pop();
                }
                if(st1.empty()){
                    ListNode* t = new ListNode(1);
                    ListNode* temp = first;
                    while(temp->next) temp = temp->next;
                    temp->next = t;
                    return first;
                }
                else st1.front()->val++;
            }
            return first;
        }
        return st1.empty() ? second : first;
    }
};