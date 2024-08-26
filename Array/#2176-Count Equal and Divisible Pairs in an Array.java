//M1
//Using iteration
//Faster than 99.16% (3ms)

class Solution {
    public int countPairs(int[] nums, int k) {
        int res = 0, n = nums.length;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] == nums[j] && (i * j) % k == 0)
                    res++;
            }
        }
        return res;
    }
}