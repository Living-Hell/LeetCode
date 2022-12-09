//M1
//Using DP
//Faster than 80.36% (15ms)

class Solution {
public:
    int minDistance(string s, string t) {
         int slen = s.size(), tlen = t.size();
        vector<vector<int>> v(slen+1, vector<int> (tlen+1,0));
        
        for(int i=0; i<=slen; i++) v[i][0] = i;
        for(int i=0; i<=tlen; i++) v[0][i] = i;
        
        for(int i=1; i<=slen; i++){
            for(int j=1; j<=tlen; j++){
                
                if(s[i-1] == t[j-1]) v[i][j] = v[i-1][j-1];
                
                else if(s[i-1] != t[j-1]){
                    int top = v[i-1][j];
                    int left = v[i][j-1];
                    int tleft = v[i-1][j-1];
                    v[i][j] = min(min(top,left),tleft) + 1;
                
                } 
            }
        }
        
        return v[slen][tlen];
    }
};