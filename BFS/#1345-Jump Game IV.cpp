// M1
// Using BFS
// Faster than 58.73% (166 ms)

class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        int n = arr.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]].push_back(i);
        }
        vector<bool> vis(n, 0);
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        int steps = 0;

        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                int ind = q.front();
                q.pop();
                if (ind == n - 1)
                    return steps;
                vector<int> &nbr = mp[arr[ind]];
                nbr.push_back(ind - 1);
                nbr.push_back(ind + 1);
                for (int i : nbr)
                {
                    if (i >= 0 and i < n and !vis[i])
                    {
                        q.push(i);
                        vis[i] = 1;
                    }
                }
                nbr.clear();
            }
            steps++;
        }
        return -1;
    }
};