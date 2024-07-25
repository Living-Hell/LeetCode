//M1
//Using disjoint set - union-find
//Faster than 47.62% (355 ms)

class UnionFind{
public:
    vector<int> rank, parent;
    int size;
    UnionFind(int n){
        size = n;
        rank.resize(n+1,0);
        for(int i=0; i<=n; i++)
            parent.push_back(i);
    }
    int find(int &a){
        if(parent[a] != a){
            parent[a] = find(parent[a]);
        }
        return parent[a];
    }
    bool Union(int &a, int &b){
        int parA = find(a), parB = find(b);
        if(parA == parB) return false;

        if(rank[parA] < rank[parB]){
            parent[parA] = parB;
        }
        else if(rank[parA] > rank[parB]){
            parent[parB] = parA;
        }
        else{
            parent[parB] = parA;
            rank[parA]++;
        }
        size--;
        return true;
    }
};


class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        UnionFind alice(n), bob(n);
        int res = 0;

        sort(edges.begin(), edges.end(), [](const vector<int> &a, const vector<int> &b){
            return a[0] > b[0];
        });

        for(auto &i:edges){
            int type = i[0], a = i[1], b = i[2];
            if(type == 3){
                res += (alice.Union(a,b) | bob.Union(a,b));
            }
            else if(type == 2){
                res += bob.Union(a,b);
            }
            else{
                res += alice.Union(a,b);
            }
        }

        if(alice.size > 1 | bob.size > 1) return -1;
        
        return edges.size() - res;
    }
};
