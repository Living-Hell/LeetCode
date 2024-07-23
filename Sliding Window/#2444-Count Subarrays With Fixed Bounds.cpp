//M1
//Using Sliding window and simulation
//Faster than 79.55% (83ms)

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();
        bool minFound = 0, maxFound = 0;
        int minInd = 0, maxInd = 0, start = 0;
        long long res = 0;

        for(int i=0; i<n; i++){
            if(nums[i] < minK or nums[i] > maxK){
                minFound = 0, maxFound = 0;
                start = i+1;
            }
            if(nums[i] == minK){
                minFound = 1;
                minInd = i;
            }
            if(nums[i] == maxK){
                maxFound = 1;
                maxInd = i;
            }
            if(minFound and maxFound){
                res += min(maxInd,minInd) - start + 1;
            }
        }
        return res;
    }
};
