//M1
//Using DP
//Faster than 57.5% (367ms)

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int N = nums.size();

        int tsum = accumulate(nums.begin(),nums.end(), 0);
        if(tsum%2==1) return 0;
        
        tsum/=2;
        vector<int> sum(tsum+1,0);
        sum[0] = 1;
        for(int i=0; i<N; i++){
            for(int j=tsum; j>=nums[i]; j--){
                if(sum[j-nums[i]] == 1)
                    sum[j] = 1;
            }   
        }
        return sum[tsum];
    }
};