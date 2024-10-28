//M1
//Using Binary Search
//Faster than 12.5% (67ms)

class Solution {
    public int find(int[] nums, int ind, int val) {
        int low = ind, high = nums.length - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == val)
                return mid;
            else if (nums[mid] < val)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }

    public int longestSquareStreak(int[] nums) {
        Arrays.sort(nums);
        int res = -1;
        for (int i = 0; i < nums.length; i++) {
            int curr = nums[i], count = 1, ind = i;
            while (ind < nums.length) {
                ind = find(nums, ind + 1, curr * curr);
                if (ind == -1)
                    break;
                count++;
                res = Math.max(res, count);
                curr = nums[ind];
            }
        }
        return res;
    }
}
