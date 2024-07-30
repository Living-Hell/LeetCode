//M1
//Using simulation and DP
//Faster than 55.5% (93ms)

class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        int res=INT_MAX, counta=0, countb=0;

        for(int i=0; i<n; i++)
            if(s[i] == 'a') 
                counta++;
        
        res = counta;

        for(int i=0; i<n; i++){
            if(s[i] == 'a')
                counta--;
            else
                countb++;
            res = min(res, counta + countb);
        }

        return res;
    }
};
