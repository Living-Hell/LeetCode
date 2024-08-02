//M1
//Using Sliding Window
//Faster than 40.47% (72ms)

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n + 1, 0);
        v[0] = 0;
        for (int i = 0; i < n; i++) {
            v[i + 1] = v[i] + (nums[i] == 1);
        }

        int st = 1, res = INT_MAX, count = v[n];

        while (st <= n) {
            int end = st + count - 1, swaps;
            if (end <= n) {
                swaps = v[end] - v[st - 1];
            } else {
                int rem = count - n + st - 1;
                swaps = v[n] - v[st - 1] + v[rem];
            }
            res = min(res, count - swaps);
            st++;
        }

        return res;
    }
};
