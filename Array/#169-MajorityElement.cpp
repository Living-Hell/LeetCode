//M1
//Using 2-pointers
//Faster than 80.64%(26ms)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int start=0, end=0;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        while(end<n){
            while(nums[start] == nums[end]){
                end++;
                if((end-start) > n/2) return nums[start];
            }
            start = end;
        }

        return nums[end];
    }
};