//M1
//Using recursion + bit manipulation
//Faster than 83.65% (10 ms)

class Solution {
public:
    int helper(vector<int> &nums, int maxOr, int currOr, int ind){
        if(ind == nums.size()) return maxOr == currOr;
        int res = 0;
        res += helper(nums,maxOr,currOr,ind+1);
        res += helper(nums,maxOr,currOr|nums[ind],ind+1);
        return res;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size(), maxOr = 0;
        for(int &i : nums)
            maxOr |= i;
        return helper(nums,maxOr,0,0);
    }
};
