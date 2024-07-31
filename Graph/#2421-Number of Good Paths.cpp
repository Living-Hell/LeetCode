//M1
//Using Disjoint Set - Union and Find
//Faster than 70% (462ms)

class UnionFind {
public:
    vector<int> rank, parent;
    int count;
    UnionFind(int n) {
        for (int i = 0; i < n; i++)
            parent.push_back(i);
        rank.resize(n, 0);
        count = n;
    }
    int Find(int x) {
        if (parent[x] != x) {
            parent[x] = Find(parent[x]);
        }
        return parent[x];
    }

    void Union(int a, int b) {
        int parA = Find(a), parB = Find(b);
        if (parA == parB)
            return;

        if (rank[parA] > rank[parB]) {
            parent[parB] = parA;

        } else if (rank[parA] < rank[parB]) {
            parent[parA] = parB;
        } else {
            parent[parA] = parB;
            rank[parA]++;
        }
    }
};

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        UnionFind uf(n);
        vector<vector<int>> adjList(n);
        map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[vals[i]].push_back(i);
        }

        for (auto& e : edges) {
            int a = e[0], b = e[1];
            if (vals[a] >= vals[b])
                adjList[a].push_back(b);
            else if (vals[b] >= vals[a])
                adjList[b].push_back(a);
        }

        int res = 0;

        for (auto i : mp) {
            for (int& j : i.second) {
                for (auto adj : adjList[j]) {
                    uf.Union(j, adj);
                }
            }
            unordered_map<int, int> conn;
            for (int& j : i.second) {
                conn[uf.Find(j)]++;
            }
            for (auto c : conn) {
                res += (c.second + 1) * c.second / 2;
            }
        }
        return res;
    }
};
