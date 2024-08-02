//M1
//Using Union Find
//Faster than 100% (0 ms)

class UnionFind {
public:
    vector<int> parent, rank;
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
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
        if (rank[parA] > rank[parB]) {
            parent[parB] = parA;
        } else if (rank[parB] > rank[parA]) {
            parent[parA] = parB;
        } else {
            parent[parB] = parA;
            rank[parA]++;
        }
    }
};

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        UnionFind uf(n);

        for (int i = 0; i < n; i += 2) {
            uf.parent[row[i]] = row[i];
            uf.parent[row[i + 1]] = row[i];
        }

        int res = 0;
        for (int i = 0; i < n; i += 2) {
            if (uf.Find(i) != uf.Find(i + 1)) {
                uf.Union(i, i + 1);
                res++;
            }
        }
        return res;
    }
};
