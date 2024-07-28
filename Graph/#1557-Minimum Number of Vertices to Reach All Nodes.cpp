//M1
//Using intuition; all the nodes with incoming edges will be connected.
//Faster than 62.11% (206ms)

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> res, vertices(n,0);
        for(auto &e : edges){
            int a = e[0], b = e[1];
            vertices[b]++;
        }
        for(int i=0; i<n; i++){
            if(vertices[i] == 0){
                res.push_back(i);
            }
        }
        return res;
    }
};
