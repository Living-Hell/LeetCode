// M1
// Using Disjoint Set
// Faster than 31.14% (180ms)

class Solution
{
public:
    class DisjointSet
    {
    public:
        vector<int> size, rank, parent;

        DisjointSet(int n)
        {
            size.resize(n + 1, 1);
            rank.resize(n + 1, 0);
            parent.resize(n + 1);
            for (int i = 0; i <= n; i++)
                parent[i] = i;
        }

        int findPar(int node)
        {
            if (node == parent[node])
                return node;
            return parent[node] = findPar(parent[node]);
        }

        void UnionByRank(int u, int v)
        {
            int upr_u = findPar(u);
            int upr_v = findPar(v);

            if (upr_u == upr_v)
                return;

            if (rank[upr_u] < rank[upr_v])
            {
                parent[upr_u] = upr_v;
            }
            else if (rank[upr_u] > rank[upr_v])
            {
                parent[upr_v] = upr_u;
            }
            else
            {
                parent[upr_u] = upr_v;
                rank[upr_v]++;
            }
        }
    };
    bool possibleBipartition(int n, vector<vector<int>> &dislikes)
    {
        vector<int> adj[n + 1];
        DisjointSet ds(n);

        for (auto p : dislikes)
        {
            int x = p[0], y = p[1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < adj[i].size(); j++)
            {
                if (ds.findPar(i) == ds.findPar(adj[i][j]))
                    return 0;
                ds.UnionByRank(adj[i][0], adj[i][j]);
            }
        }
        return 1;
    }
};

// M2
// Using DFS
// Faster than 49.12% (167ms)

class Solution
{
public:
    bool possibleBipartition(int n, vector<vector<int>> &dislikes)
    {
        vector<int> color(n + 1, 0);
        vector<int> adj[n + 1];

        for (auto p : dislikes)
        {
            int x = p[0], y = p[1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        for (int i = 1; i <= n; i++)
        {
            if (color[i] == 0)
            {
                color[i] = 1;
                queue<int> q;
                q.push(i);
                while (!q.empty())
                {
                    int root = q.front();
                    q.pop();
                    for (int node : adj[root])
                    {
                        if (color[node] and color[node] == color[root])
                            return 0;
                        if (!color[node])
                        {
                            color[node] = -1 * color[root];
                            q.push(node);
                        }
                    }
                }
            }
        }
        return 1;
    }
};