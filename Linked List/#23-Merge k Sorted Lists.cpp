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

// M2
// Using divide and conquer
// Faster than 97.07% (9ms)

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *ans = new ListNode(0);
        ListNode *temp = ans;
        while (list1 and list2)
        {
            if (list1->val <= list2->val)
            {
                temp->next = list1;
                list1 = list1->next;
                temp = temp->next;
            }
            else
            {
                temp->next = list2;
                list2 = list2->next;
                temp = temp->next;
            }
        }
        if (!list1)
            temp->next = list2;
        else
            temp->next = list1;
        return ans->next;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int n = lists.size();
        if (n == 0)
            return NULL;
        int st = 0, end = n - 1, temp;
        while (end != 0)
        {
            temp = end, st = 0;
            while (st < temp)
            {
                lists[st] = mergeTwoLists(lists[st], lists[temp]);
                st++;
                temp--;
                if (st >= temp)
                {
                    end = temp;
                }
            }
        }
        return lists[0];
    }
};