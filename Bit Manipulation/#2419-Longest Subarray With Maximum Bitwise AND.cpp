//M1
//Using bit manpipulation and maths
//Faster than 62.28% (104ms)

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), maxm = *max_element(nums.begin(), nums.end()), res = 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == maxm) {
                int j = i;
                while (j < n and nums[j] == maxm)
                    j++;
                res = max(res, j - i);
                i = j;
            }
        }
        return res;
    }
};
