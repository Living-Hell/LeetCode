//M1
//Using BFS-Kahn's Algorithm
//Faster than 41.82%(33ms)

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adj(numCourses);
        queue<int> q;

        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }

        for(int i=0; i<numCourses; i++)
            if(indegree[i] == 0)
                q.push(i);
        
        int count=0;
        while(!q.empty()){
            int top = q.front();
            count++;
            q.pop();
            for(int i :adj[top]){
                indegree[i]--;
                if(indegree[i] == 0)
                    q.push(i);
            }
        }
        return count == numCourses;
    }
};