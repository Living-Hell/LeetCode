//Using intuition and simulation
//Faster than 50.71% (2 ms)

class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a == b) return -1;

        int n1 = a.size(), n2 = b.size();
        if(n1 != n2) return max(n1,n2);
        
        for(int i=0; i<n1; i++){
            if(a[i] != b[i])
                return n1;
        }
        return -1;
    }
};