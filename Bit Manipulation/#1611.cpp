//M1
//Using dp, maths and bit manipulation
//Faster than 100% (0ms)

class Solution {
public:
    unordered_map<int,int> mp;
    int msb(int n)
    {
        int ans = 1;
        while (n) {
            ans *= 2;
            n /= 2;
        }
        ans/=2;
        return ans;
    }

    int solve(int n){
        if(n == 0) return 0;
        if(n==1) return 1;

        if(mp.find(n) != mp.end()) return mp[n];
        
        int res = 0;
        int setBit = msb(n);
        res += 2*setBit - 1 - solve(n-setBit);
        return mp[n] = res;
    }

    int minimumOneBitOperations(int n) {
      return solve(n);   
    }
};