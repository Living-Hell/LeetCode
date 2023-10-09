// M1
// Using max heap
// Faster than 35% (260 ms)

class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        priority_queue<pair<long, pair<int, int>>> pq;
        long n = nums1.size(), m = nums2.size();
        k = min((long)k, m * n);

        for (int a : nums1)
        {
            for (int b : nums2)
            {
                long sum = a + b;
                if (pq.size() == k and pq.top().first > sum)
                    pq.pop();
                else if (pq.size() == k and pq.top().first <= sum)
                    break;
                pq.push({sum, {a, b}});
            }
        }

        vector<vector<int>> ans;
        while (!pq.empty())
        {
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};

// M2
// Using BFS
// Faster than 55.49% (240ms)

class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        vector<vector<int>> ans;
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        long n = nums1.size(), m = nums2.size();
        set<pair<int, int>> vis;

        pq.push({nums1[0] + nums2[0], 0, 0});
        vis.insert({0, 0});

        while (!pq.empty())
        {
            auto [sum, i, j] = pq.top();
            pq.pop();
            k--;
            ans.push_back({nums1[i], nums2[j]});
            if (k == 0)
                return ans;

            if (i + 1 < n and vis.count({i + 1, j}) == 0)
            {
                pq.push({nums1[i + 1] + nums2[j], i + 1, j});
                vis.insert({i + 1, j});
            }

            if (j + 1 < m and vis.count({i, j + 1}) == 0)
            {
                pq.push({nums1[i] + nums2[j + 1], i, j + 1});
                vis.insert({i, j + 1});
            }
        }
        return ans;
    }
};