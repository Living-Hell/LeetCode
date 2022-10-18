//M1
//Counting the frequency and last index
//Faster than 65.92% (13ms)

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n = nums.size();
        
		//Take a counter to count the no. of elements as target in array and lindex to store the last index
		//where the target element occurs
        int count = 0, lindex = 0;
        
        for(int i=0; i<n; i++){
		//whenever target == nums[i] increase the count by 1 and update the lindex
            if(nums[i] == target){
                count++;
                lindex = i;
            }
        }
        
		//if count == 0 this implies target element is not in the array
        if(!count)
            return {-1,-1};
        
		//else simply return the last index where element occured - no. of target elements present + 1
		//and the last index of the target element lindex
        return {lindex - count + 1, lindex};
        
    }
};