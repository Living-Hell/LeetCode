// M1
// Using Priority Queue and Dijkstra's Algorithm
// Faster than 61.6% (62ms)

class Solution
{
public:
    int countPaths(int n, vector<vector<int>> &roads)
    {
        int mod = 1e9 + 7;
        vector<pair<int, int>> adjList[n];
        for (auto i : roads)
        {
            adjList[i[0]].push_back({i[1], i[2]});
            adjList[i[1]].push_back({i[0], i[2]});
        }

        vector<long> dist(n, 1e15), path(n, 0);

        priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> pq;

        dist[0] = 0;
        path[0] = 1;

        pq.push({0, 0});

        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();

            long node = top.second;
            long dis = top.first;

            for (auto &i : adjList[node])
            {
                long wt = i.second;
                long nbr = i.first;

                if (dist[nbr] > dis + wt)
                {
                    dist[nbr] = dis + wt;
                    pq.push({dis + wt, nbr});
                    path[nbr] = path[node];
                }
                else if (dist[nbr] == dis + wt)
                {
                    path[nbr] = (path[node] + path[nbr]) % mod;
                }
            }
        }
        return path[n - 1];
    }
};