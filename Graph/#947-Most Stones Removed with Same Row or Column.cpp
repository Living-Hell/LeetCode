//M1
//Using Union Find
//Faster than 46.92% (39ms)

class Solution {
public:
    int Find(int par[], int x) {
        if (par[x] == x)
            return x;
        return par[x] = Find(par, par[x]);
    }
    void Union(int par[], int a, int b) {
        int parA = Find(par, a), parB = Find(par, b);
        if (parA == parB)
            return;
        par[parB] = parA;
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int par[n];
        for (int i = 0; i < n; i++)
            par[i] = i;

        unordered_map<int, vector<int>> col, row;

        for (int i = 0; i < n; i++) {
            int a = stones[i][0], b = stones[i][1];
            col[b].push_back(i);
            row[a].push_back(i);
        }
        for (int i = 0; i < n; i++) {
            int a = stones[i][0], b = stones[i][1];
            for (int& x : row[a])
                Union(par, i, x);
            for (int& x : col[b])
                Union(par, i, x);
        }
        unordered_set<int> st;
        for (int i = 0; i < n; i++)
            st.insert(Find(par, par[i]));
        return n - st.size();
    }
};
