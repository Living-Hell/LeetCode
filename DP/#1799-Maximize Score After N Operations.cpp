//M1
//Using DP and Bitset
//Faster than 83.18% (73 ms)

class Solution {
public:
    int dp[1 << 14][8];
    int solve(vector<int>& nums, int n, int mask, int op) {
        if (mask == (1 << n) - 1)
            return 0;
        if (dp[mask][op] != -1)
            return dp[mask][op];
        int res = 0;

        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) != 0)
                continue;
            for (int j = i + 1; j < n; j++) {
                if ((mask & (1 << j)) != 0)
                    continue;
                int newMask = mask | (1 << i) | (1 << j);
                res = max(res, (op * __gcd(nums[j], nums[i])) +
                                   solve(nums, n, newMask, op + 1));
            }
        }
        return dp[mask][op] = res;
    }
    int maxScore(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(nums, nums.size(), 0, 1);
    }
};
