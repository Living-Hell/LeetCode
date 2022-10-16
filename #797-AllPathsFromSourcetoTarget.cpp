//M1
//DFS using recursion
//Faster than 44.84% (30ms)

class Solution {
public:
    int target;
    vector<vector<int>> ans;
    vector<int> temp;
    
    void helper(vector<vector<int>>& graph, int curr_node = 0){
        temp.push_back(curr_node);
        
        if(curr_node == target){
            ans.push_back(temp);
        }
        
        else
            for(int node : graph[curr_node])
                helper(graph, node);
        
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        target = graph.size() - 1;
        
        helper(graph);
        
        return ans;
        
    }
};