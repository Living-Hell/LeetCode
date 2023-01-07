//M1
//Using Greedy
//Faster Than 46.84%(5ms)

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        int incr = 1, decr = 1;
        
        for(int i=1; i<n; i++){
            if(nums[i]>nums[i-1])
                incr = decr + 1;
            else if(nums[i]<nums[i-1])
                decr = incr + 1;
        }
        return max(incr,decr);
    }
};