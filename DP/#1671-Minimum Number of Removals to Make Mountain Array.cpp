//M1
//Using DP
//Faster than 28.79% (75ms)

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size(),i,j;
        vector<int> dp(n);
        for(i = 0; i < n; i++){
            dp[i] = 1;
            for(j = i-1; j >= 0; j--){
                if(nums[j]<nums[i]&&dp[i]<dp[j]+1){
                    dp[i] = dp[j]+1;
                }
            }
        }
        vector<int> r(n);
        for(i = n-1; i >= 0; i--){
            r[i] = 1;
            for(j = i+1; j < n; j++){
                if(nums[j]<nums[i]&&r[i]<r[j]+1){
                    r[i] =r[j]+1;
                }
            }
        }
        int ans = 0;
        for(i = 1; i < n-1; i++){
            if(dp[i]>1&&r[i]>1){
                ans = max(ans,dp[i]+r[i]-1);
            }
        }
        return n-ans;
    }
};
