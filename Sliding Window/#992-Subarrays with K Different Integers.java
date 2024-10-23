//M1
//Using sliding window, 2 pointer and hashmap
//Faster than 85.59% (39ms)

class Solution {
    public int subarrayAtMostK(int[] nums, int k) {
        int st = 0, end = 0, n = nums.length, res = 0;
        HashMap<Integer, Integer> mp = new HashMap<>();
        while (end < n) {
            if (mp.containsKey(nums[end])) {
                mp.put(nums[end], mp.get(nums[end]) + 1);
            } else {
                mp.put(nums[end], 1);
            }
            while (mp.size() > k) {
                if (mp.get(nums[st]) == 1) {
                    mp.remove(nums[st]);
                } else {
                    mp.put(nums[st], mp.get(nums[st]) - 1);
                }
                st++;
            }
            res += end - st + 1;
            end++;
        }
        return res;
    }
    public int subarraysWithKDistinct(int[] nums, int k) {
        return subarrayAtMostK(nums,k) - subarrayAtMostK(nums,k-1);
    }
}
