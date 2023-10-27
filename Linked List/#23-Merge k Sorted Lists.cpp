// M1
// Using priority queue
// Faster than 53.49% (19 ms)

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = lists.size();
        for (int i = 0; i < n; i++)
        {
            ListNode *temp = lists[i];
            while (temp)
            {
                pq.push(temp->val);
                temp = temp->next;
            }
        }
        ListNode *ans = new ListNode(0);
        ListNode *temp = ans;
        while (!pq.empty())
        {
            temp->next = new ListNode(pq.top());
            temp = temp->next;
            pq.pop();
        }
        return ans->next;
    }
};