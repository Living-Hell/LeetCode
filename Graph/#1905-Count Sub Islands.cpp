//M1
//Using Union-Find Disjoint Set
//Faster than 43.32% (240ms)

class UnionFind {
public:
    vector<int> parent, rank;
    int n;
    UnionFind(int len) {
        n = len;
        rank.resize(len, 1);
        for (int i = 0; i < len; i++)
            parent.push_back(i);
    }
    int Find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = Find(parent[x]);
    }
    void Union(int a, int b) {
        int parA = Find(a), parB = Find(b);
        if (parA == parB)
            return;
        n--;
        if (rank[parA] > rank[parB]) {
            parent[parB] = parA;
        } else if (rank[parA] < rank[parB]) {
            parent[parA] = parB;
        } else {
            rank[parA]++;
            parent[parB] = parA;
        }
    }
};
class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {
        vector<pair<int, int>> dir = {{1, 0}, {0, 1}};
        int m = grid1.size(), n = grid2[0].size();
        UnionFind uf(m * n);

        vector<bool> vis(m * n, 0);

        queue<int> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j]) {
                    int ind1 = i * n + j;
                    for (auto [a, b] : dir) {
                        int x = i + a, y = j + b;
                        if (x >= m or y >= n or !grid2[x][y])
                            continue;
                        int ind2 = x * n + y;
                        uf.Union(ind1, ind2);
                    }
                } else {
                    uf.n--;
                }
            }
        }
        unordered_set<int> st;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid2[i][j])
                    continue;

                if (!grid1[i][j]) {
                    int par = uf.Find(i * n + j);
                    st.insert(par);
                }
            }
        }
        return uf.n - st.size();
    }
};
