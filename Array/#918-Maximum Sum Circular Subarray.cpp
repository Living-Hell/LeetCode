//M1
//Using simulation
//Faster than 31.89% (49ms)

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int res = INT_MAX, temp = 0, n = nums.size(), tsum = 0, temp2 = 0, res2 = INT_MIN;
        for(int i=0; i<n; i++){
            tsum += nums[i];
            temp = min(temp + nums[i], nums[i]);
            res = min(res,temp);
            temp2 = max(temp2 + nums[i], nums[i]);
            res2 = max(res2, temp2);
        }
        if(res == tsum) return res2;
        return max(res2,tsum - res);
    }
};
