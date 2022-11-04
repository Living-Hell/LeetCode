//M1
//Iteration
//Faster than 46.13% (354ms)

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        if( n == trust.size())
            return -1;
        
        vector<int> trusted(n+1,0), trusting(n+1,0);
        
        for(int i=0; i<trust.size(); i++){
            trusted[trust[i][1]]++;
            trusting[trust[i][0]]--;
        }
        
        for(int i=1; i<=n; i++){
            if(trusted[i] ==(n-1)){
                if(trusting[i] == 0){
                    return i;
                }
            }
        }
        
        return -1;
        
    }
};