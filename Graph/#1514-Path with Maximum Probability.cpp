//M1
//Using Djikstra's Algorithm
//Faster than 5.85% (286ms)

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> prob(n, 0);
        vector<vector<pair<int, double>>> adj(n);

        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0], b = edges[i][1];
            double p = succProb[i];
            adj[a].push_back({b, p});
            adj[b].push_back({a, p});
        }

        prob[start_node] = 1;

        priority_queue<pair<int, double>> pq;

        pq.push({start_node, 1});

        while (!pq.empty()) {
            auto [node, probb] = pq.top();
            pq.pop();
            for (auto& a : adj[node]) {
                if (probb * a.second > prob[a.first]) {
                    prob[a.first] = probb * a.second;
                    pq.push({a.first, prob[a.first]});
                }
            }
        }

        return prob[end_node];
    }
};
