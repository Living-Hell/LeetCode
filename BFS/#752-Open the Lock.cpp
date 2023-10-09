// M1
// Using BFS and sets
// Faster than 57.22% (172ms)

class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
    {
        string curr = "0000";
        unordered_set<string> st(deadends.begin(), deadends.end()), vis;
        if (st.find("0000") != st.end())
            return -1;

        queue<pair<string, int>> q;
        q.push({curr, 0});
        vis.insert(curr);

        while (!q.empty())
        {
            auto top = q.front();
            q.pop();

            string s = top.first;
            int steps = top.second;

            if (s == target)
                return steps;

            string up, down;

            for (int i = 0; i < 4; i++)
            {
                up = down = s;
                int curr = s[i] - '0';
                int t1 = (curr == 9 ? 0 : curr + 1) + '0', t2 = (curr == 0 ? 9 : curr - 1) + '0';

                up[i] = t1, down[i] = t2;

                if (st.find(up) == st.end() and vis.find(up) == st.end())
                {
                    vis.insert(up);
                    q.push({up, steps + 1});
                }

                if (st.find(down) == st.end() and vis.find(down) == st.end())
                {
                    vis.insert(down);
                    q.push({down, steps + 1});
                }
            }
        }
        return -1;
    }
};