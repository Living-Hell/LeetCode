//M1
//Using graph and bfs
//Faster than 100% (0ms)

class Solution {
public:
    double helper(map<string, vector<pair<string, double>>> adj, string st, string end) {
        if (!adj.contains(st) || !adj.contains(end))
            return -1.0;
        queue<pair<string, double>> q;
        unordered_set<string> vis;
        q.push({st, 1.0});
        vis.insert(st);
        double res = -1;
        while (!q.empty()) {
            string top = q.front().first;
            double val = q.front().second;
            q.pop();
            if (top == end)
                return val;
            for (auto& e : adj[top]) {
                string node = e.first;
                double wt = e.second;
                if (!vis.count(node)) {
                    q.push({node, val * wt});
                    vis.insert(node);
                }
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<string, vector<pair<string, double>>> adj;
        int n = equations.size();
        for (int i = 0; i < n; i++) {
            string a = equations[i][0], b = equations[i][1];
            double wt = values[i];
            adj[a].push_back({b, wt});
            adj[b].push_back({a, 1 / wt});
        }
        vector<double> res;
        for (auto& q : queries) {
            res.push_back(helper(adj, q[0], q[1]));
        }
        return res;
    }
};
