class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size(), ans=0, diff = INT_MAX;
        
        for(int i = 0; i<n-1; i++){
            
            int start = i+1, end = n-1;
        
            while(start<end){
            
                int sum = nums[start] + nums[end] + nums[i];
                
                if(sum < target) start++;
                
                else if (sum> target) end--;
                
                else return sum;
                
                if(abs(sum-target) < diff){
                    diff = abs(sum-target);
                    ans = sum;
                }
                
            }
        }
        
        return ans;
        
    }
};