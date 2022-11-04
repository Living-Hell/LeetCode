//M1
//Two-pointer method
// Faster Than 55.11% (10ms)

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int n = nums.size();
        
        if(n<3) return n;
        
        int k=2;
        
        for(int i=2; i<n; i++){
            if(nums[i] != nums[k-2])
                nums[k++] = nums[i];
        }
                
        return k;
    }
};