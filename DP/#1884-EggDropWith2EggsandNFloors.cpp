//M1
//Using Dp
//Faster than 100% (0ms)

class Solution {
public:
    int twoEggDrop(int n) {
        int ans = ceil((-1+sqrt(1+8*n))/2);
        return ans;
    }
};