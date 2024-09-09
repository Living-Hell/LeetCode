//M1
//Using BFS and Bitmask
//Faster than 69.36% (22ms)

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size(), total = (1 << n) - 1;
        vector<vector<bool>> vis(n, vector<bool>(total, 0));
        queue<tuple<int, int, int>> q;
        for (int i = 0; i < n; i++) {
            q.push({i, 1 << i, 0});
            vis[i][1 << i] = 1;
        }
        int res = 0;
        while (!q.empty()) {
            auto [node, mask, dist] = q.front();
            q.pop();
            if (mask == total)
                return dist;
            for (int i : graph[node]) {
                if (!vis[i][mask]) {
                    vis[i][mask] = 1;
                    int newMask = mask | 1 << i;
                    q.push({i, newMask, dist + 1});
                }
            }
        }
        return -1;
    }
};
