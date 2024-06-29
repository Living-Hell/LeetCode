//Using simulation
//Faster than 33.03% (3ms)

class Solution {
public:
    int countSegments(string s) {
        int n = s.size();
        if(n==0) return 0;

        int count = 0, i = 0;

        while(i<n){
            while(i<n and s[i] == ' ') i++;
            if(i<n and s[i] != ' ') count++;
            while(i<n and s[i] != ' ') i++;
        }
        return count;
    }
};