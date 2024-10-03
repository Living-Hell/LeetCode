//M1
//Using hashmap and sliding window
//Faster than 84.32% (127ms)

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int res = n, tsum = 0, currSum = 0;

        for(int &i:nums) tsum = (i + tsum)%p;

        if(tsum == 0) return 0;

        unordered_map<int,int> mp;
        mp[0] = -1;

        for(int i=0; i<n; i++){
            currSum = (currSum + nums[i])%p;
            int req = (p - (tsum - currSum))%p;
            if(mp.contains(req)){
                res = min(res,i-mp[req]);
            }
            mp[currSum] = i;
        }

        return res == n ? -1 : res;
    }
};
