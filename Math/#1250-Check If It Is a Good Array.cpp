//M1
//Using GCD
//Faster than 60.70% (38 ms)

class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int n = nums.size();
        int gcd = nums[0];
        for(int i=1; i<n; i++){
            gcd = __gcd(gcd,nums[i]);
        }
        return gcd == 1;
    }
};
