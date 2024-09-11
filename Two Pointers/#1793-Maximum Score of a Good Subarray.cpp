//M1
//Using two pointers
//Faster than 41.28 % (131ms)

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size(), left = k, right = k, minm = nums[k], res = nums[k];
        while (left > 0 or right < n - 1) {
            if (left == 0 or (right < n - 1 and nums[left - 1] < nums[right + 1]))
                right++;
            else
                left--;
            minm = min({minm, nums[left], nums[right]});
            res = max(res, minm * (right - left + 1));
        }
        return res;
    }
};
