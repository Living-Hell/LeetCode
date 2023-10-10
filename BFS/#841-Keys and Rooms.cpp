// M1
// Using BFS
// Faster than 74.17% (7ms)

class Solution
{
public:
    bool canVisitAllRooms(vector<vector<int>> &rooms)
    {
        int n = rooms.size();
        vector<bool> vis(n, 0);
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        int count = n;
        while (!q.empty())
        {
            int top = q.front();
            q.pop();
            count -= 1;
            for (int i : rooms[top])
            {
                if (!vis[i])
                {
                    vis[i] = 1;
                    q.push(i);
                }
            }
        }
        return count == 0;
    }
};