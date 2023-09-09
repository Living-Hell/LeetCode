// M1
// Using Topological sorting through indegree method
// Faster than 91.28% (13ms)

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        queue<int> q;

        for (int i = 0; i < prerequisites.size(); i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        for (int i = 0; i < numCourses; i++)
            if (indegree[i] == 0)
                q.push(i);

        vector<int> ans;
        while (!q.empty())
        {
            int top = q.front();
            ans.push_back(top);
            q.pop();
            for (int i : adj[top])
            {
                indegree[i]--;
                if (indegree[i] == 0)
                    q.push(i);
            }
        }
        return ans.size() == numCourses ? ans : vector<int>();
    }
};