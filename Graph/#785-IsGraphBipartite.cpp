//M1
//Using Dfs
//Faster than 74.23%(25ms)

class Solution {
public:
    bool coloringBipartite(int node, int col, vector<vector<int>>& graph, vector<int> &color){
        color[node] = col;
        for(int i:graph[node]){
            if(color[i] == col) return 0;
            else if(color[i] == -1){
                if(!coloringBipartite(i,!col,graph,color))
                    return 0;
            }
        }
        return 1;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> color(v,-1);
	    for(int i=0; i<v; i++){
    	    if(color[i] == -1 && !coloringBipartite(i,0,graph,color)) 
    	        return 0;
	    }
    	return 1;
    }
};