//M1
//Using Union-Find
//Faster than 90.49% (117ms)

class DisjointSet{
public:
    vector<int> size, rank, parent;
    DisjointSet(int n){
        size.resize(n+1,1);
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0; i<=n; i++) parent[i]=i;
    }

    int findPar(int node){
        if(node == parent[node])
            return node;
        return parent[node] = findPar(parent[node]);
    }

    void UnionByRank(int u, int v){
        int upr_u = findPar(u);
        int upr_v = findPar(v);

        if(upr_u == upr_v)  return;

        if(rank[upr_u] < rank[upr_v]){
            parent[upr_u] = upr_v;
        }
        else if(rank[upr_u] > rank[upr_v]){
            parent[upr_v] = upr_u;
        }
        else{
            parent[upr_u] = upr_v;
            rank[upr_v]++;
        }
    }

    void UnionBySize(int u, int v){
        int upr_u = findPar(u);
        int upr_v = findPar(v);

        if(upr_u == upr_v) return;

        if(size[upr_u] > size[upr_v]){
            parent[upr_v] = upr_u;
            size[upr_u] += size[upr_v];
        }
        else{
            parent[upr_u] = upr_v;
            size[upr_v] += size[upr_u];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);

        int comp=0, ex_edges=0;

        for(auto i:connections){
            if(ds.findPar(i[0]) == ds.findPar(i[1])) ex_edges++;
            else ds.UnionBySize(i[0], i[1]);
        }

        for(int i=0; i<n; i++)
            if(ds.parent[i] == i)
                comp++;
                
        comp--;

        return ex_edges >= comp? comp : -1;
    }
};