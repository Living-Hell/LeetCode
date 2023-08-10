//M1
//Using binary search
//Faster than 91.34% (3ms)

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high  = n-1, mid;
        while(low<=high){
            mid = (low + high)/2;
            if(nums[mid] == target)
                return 1;
            if(nums[mid] == nums[low] and nums[mid] == nums[high]){
                low++;
                high--;
            }
            else if(nums[low] <= nums[mid]){
                if(nums[mid] >= target and nums[low] <= target)
                    high = mid-1;
                else
                    low = mid+1;
            }
            else{                
                if(nums[mid] <= target and nums[high] >= target)
                    low = mid+1;
                else
                    high = mid-1;
            }
        }
        return 0;
    }
};