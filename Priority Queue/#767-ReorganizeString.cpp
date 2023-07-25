// M1
// USing priority queue and inserting 2 elements at once
// Faster than 33.41% (5ms)

class Solution
{
public:
    string reorganizeString(string s)
    {
        if (s.size() == 1)
            return s;
        int a[26] = {0};
        for (int i = 0; i < s.size(); i++)
            a[s[i] - 'a']++;
        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < 26; i++)
            if (a[i] > 0)
                pq.push({a[i], i + 'a'});
        string ans = "";
        if (pq.size() == 1)
            return "";
        while (pq.size() > 1)
        {
            auto top1 = pq.top();
            pq.pop();
            auto top2 = pq.top();
            pq.pop();
            char c1 = top1.second, c2 = top2.second;
            int f1 = top1.first, f2 = top2.first;
            ans.push_back(c1);
            ans.push_back(c2);
            f1--;
            f2--;
            if (f1 > 0)
                pq.push({f1, c1});
            if (f2 > 0)
                pq.push({f2, c2});
        }
        if (pq.size() > 0)
        {
            int f = pq.top().first;
            char c = pq.top().second;
            if (f > 1)
                return "";
            ans.push_back(c);
        }
        return ans;
    }
};
