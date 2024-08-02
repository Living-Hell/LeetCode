//M1
//Using Disjoint Sets - Union-Find
//Faster than 49.63% (181ms)

class UnionFind{
public:
    vector<int> parent, rank;
    UnionFind(int n){
        rank.resize(n,0);
        for(int i=0; i<n; i++){
            parent.push_back(i);
        }
    }
    int Find(int x){
        if(parent[x] == x)
            return x;
        return parent[x] = Find(parent[x]);
    }
    void Union(int a, int b){
        int parA = Find(a), parB = Find(b);
        if(parA == parB) return;
        if(rank[parA] > rank[parB])
            parent[parB] = parA;
        else if(rank[parB] > rank[parA])
            parent[parA] = parB;
        else{
            parent[parB] = parA;
            rank[parA]++;
        }
    }
};

class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        UnionFind uf(n);
        vector<bool> res(requests.size(),0);

        for(int i=0; i<requests.size(); i++){
            int a = requests[i][0], b = requests[i][1];                         
            UnionFind uf1 = uf;
            uf1.Union(a,b);
            bool check = 1;
            for(int i=0; i<restrictions.size(); i++){
                int x = restrictions[i][0], y = restrictions[i][1];
                if(uf1.Find(x) == uf1.Find(y)){
                    check = 0;
                    break;
                }
            }
            if(check){
                uf.Union(a,b);
                res[i] = 1;
            }
        }
        return res;
    }
};
