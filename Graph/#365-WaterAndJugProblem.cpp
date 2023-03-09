//M1
///using BFS
//Faster than 33.4%(46ms)

class Solution {
public:
    bool canMeasureWater(int jug1, int jug2, int target) {
        vector<int> adj = {jug1, jug2, -jug1, -jug2};
        queue<int> q;
        vector<bool> visited(jug1+jug2+1,0);

        visited[0]=1;
        q.push(0);

        while(!q.empty()){
            int top = q.front(); //cout<<top<<" ";
            q.pop();

            if(top == target) return true;

            for(int i:adj){
                int node = top+i; //cout<<node<<" ";
                if(node>=0 && node<=jug1+jug2 && !visited[node]){
                    visited[node]=1;
                    q.push(node);
                }
            }
        }
        return false;
    }
};