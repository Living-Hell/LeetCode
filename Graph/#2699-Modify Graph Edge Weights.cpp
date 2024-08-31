//M1
//Using djikstra's algorithm
//Faster than 55.87%(603ms)

class Solution {
public:
    vector<int> djikstra(int n, vector<vector<pair<int, int>>>& adjList,
                         int source) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        vector<int> dist(n, INT_MAX);

        dist[source] = 0;
        pq.push({0, source});

        while (!pq.empty()) {
            auto [len, node] = pq.top();
            pq.pop();

            for (auto& aj : adjList[node]) {
                int b = aj.first, w = aj.second;
                w = w == -1 ? 1 : w;
                if (len + w < dist[b]) {
                    dist[b] = len + w;
                    pq.push({dist[b], b});
                }
            }
        }
        return dist;
    }
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges,
                                           int source, int destination,
                                           int target) {
        vector<vector<pair<int, int>>> adjList(n);
        vector<int> depNodes;

        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0], b = edges[i][1], wt = edges[i][2];
            if (wt == -1)
                continue;
            adjList[a].push_back({b, wt});
            adjList[b].push_back({a, wt});
        }

        vector<vector<int>> res;

        vector<int> dist = djikstra(n, adjList, source);
        if (dist[destination] < target)
            return res;

        if (dist[destination] < target)
            return res;

        if (dist[destination] == target) {
            for (auto& e : edges) {
                if (e[2] == -1) {
                    e[2] = 2e9;
                }
            }
            return edges;
        }

        for (int i = 0; i < edges.size(); i++) {
            int a = edges[i][0], b = edges[i][1], wt = edges[i][2];
            if (wt == -1) {
                edges[i][2] = 1;
                adjList[a].push_back({b, 1});
                adjList[b].push_back({a, 1});
                dist = djikstra(n, adjList, source);
                if (dist[destination] <= target) {
                    edges[i][2] += target - dist[destination];
                    for (int j = i + 1; j < edges.size(); j++) {
                        if (edges[j][2] == -1) {
                            edges[j][2] = 2e9;
                        }
                    }
                    return edges;
                }
            }
        }
        return res;
    }
};
