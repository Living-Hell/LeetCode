//Using simulation
//Faster than 47.9% (4 ms)

class Solution {
public:
    string reverseSt(string s){
        int n = s.size();
        for(int i=0; i<n/2; i++){
            char c = s[i];
            s[i] = s[n-i-1];
            s[n-i-1] = c;
        }
        return s;
    }
    string reverseStr(string s, int k) {
        int n = s.size(), i=0;
        string res="";
        while(i<n){
            res += reverseSt(s.substr(i,min(k,n-i)));
            if(i+k<n) res +=  s.substr(i+k, min(k,n-i-k));
            i += 2*k;
        }
        return res;
    }
};