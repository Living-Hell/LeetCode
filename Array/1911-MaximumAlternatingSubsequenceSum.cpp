//M1
//Using 2 Pointers(or DP idk)
//Faster than 88.43%(188ms)

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        if(n==1) return nums[0];
        else if(n==2) return max(nums[0],nums[1]);

        int sum = 0, sub = INT_MAX;
        long long ans=0;

        for(int i=1; i<n; i++){
            if(nums[i] > nums[i-1]){
                if(sub!= INT_MAX) ans-= sub;
                sub = INT_MAX;
                sum = max(sum,nums[i]);

            }
            else if(nums[i] < nums[i-1]){
                ans+= sum;
                sum = 0;
                sub = min(sub, nums[i]);
            }
        }
        if(nums[1]<nums[0]) ans+= nums[0];
        ans+= sum;
        if(ans==0) ans += nums[0];
        return ans;
        
    }
};