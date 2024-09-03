//M1
//Using 2 pointers
//Faster than 32.76% (8ms)

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int st = 0, end = 1, n = nums.size(), res = 1;
        while(end < n){
            while(end < n and nums[end] > nums[end-1]) end++;
            res = max(res, end-st);
            st = end;
            end++;
        }
        return res;
    }
};
