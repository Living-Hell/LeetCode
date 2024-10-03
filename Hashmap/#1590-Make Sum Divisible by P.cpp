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

//M2
//Using hashmap and sliding window
//Faster than 34.7% (143ms)

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        nums[0] %= p;
        for (int i = 1; i < n; i++) {
            nums[i] = (nums[i] % p + nums[i - 1]) % p;
        }
        unordered_map<int, int> mp;
        int res = n, rem = nums[n - 1];

        if (rem == 0)
            return rem;

        mp[0] = -1;

        for (int i = 1; i < n; i++) {
            int currRem = (p - (rem - nums[i - 1])) % p;
            if (mp.contains(currRem)) {
                res = min(res, i - mp[currRem] - 1);
            }
            if (nums[i - 1] == 0)
                res = min(res, n - i);
            mp[nums[i - 1]] = i - 1;
        }
        return res == n ? -1 : res;
    }
};
