//M1
//Using Union Find Method 
//Faster than 97.27% (4ms)

class Solution {
public:
    vector<int> parent;
    
    int find_set(int x){
        if(parent[x] == x)
            return x;
        return parent[x] = find_set(parent[x]);
    }
    
    bool union_set(int x, int y){
        int a = find_set(x);
        int b = find_set(y);
        
        if(a==b)
            return true;
        
        parent[b] = a; 
        return false;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        
        for(int i=0; i<=n; i++){
            parent.push_back(i);
        }
        
        for(auto edge : edges){
            if(union_set(edge[0], edge[1]))
                return {edge[0], edge[1]};
        }
        
        return {-1,-1,};
        
    }
};

//M2
//Using Union Find Method 
//Faster than 92.51% (7ms)

class Solution {
public:
    vector<int> parent;
    
    int find(int node) {
        while(parent[node] != node) {
            node = parent[node];
        }
        
        return node;
    }
    
    void union_set(int i, int j) {
        int iRoot = find(i);
        int jRoot = find(j);
        
        if(iRoot != jRoot) {
            parent[jRoot] = iRoot;
        }
        
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        //make each node the parent of itself
        for(int i = 0; i <=n; i++) parent.push_back(i);
        
        //Loop on all edges
        for(auto edge : edges) {
            if(find(edge[0]) == find(edge[1])) return edge;
            union_set(edge[0], edge[1]);
        }
        
        return {-1,-1};
    }
};


