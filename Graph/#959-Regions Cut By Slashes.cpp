//M1
//Using Union Find
//Faster than 84.42% (4ms)

class Solution {
public:
    int find(int par[], int x) {
        if (par[x] == x)
            return x;
        return find(par, par[x]);
    }
    void Union(int par[], int a, int b) {
        int parA = find(par, a), parB = find(par, b);
        par[parA] = parB;
    }
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int par[n * n * 4];
        for (int i = 0; i < n * n * 4; i++)
            par[i] = i;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int base = 4 * n * i + 4 * j;
                if (grid[i][j] != '/') {
                    Union(par, base, base + 2);
                    Union(par, base + 1, base + 3);
                }
                if (grid[i][j] != '\\') {
                    Union(par, base, base + 1);
                    Union(par, base + 2, base + 3);
                }
                if (j < n - 1)
                    Union(par, base + 2, base + 5);
                if (i < n - 1)
                    Union(par, base + 3, 4 * n * (i + 1) + 4 * j);
            }
        }

        int res = 0;
        for (int i = 0; i < 4 * n * n; i++)
            if (par[i] == i)
                res++;
        return res;
    }
};
