//M1
//Using prefix sum
//Faster than 81.35% (77ms)

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<long long int> pref(n + 1);
        pref[0] = 0;
        int mod = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + nums[i];
        }

        vector<long long int> subSum;
        for (int len = 0; len < n; len++) {
            int st = 1, end = st + len;
            while (end <= n) {
                long long int subArrSum = (pref[end] - pref[st - 1]) % mod;
                subSum.push_back(subArrSum);
                st++;
                end++;
            }
        }

        sort(subSum.begin(), subSum.end());

        long long int res = 0;
        for (int i = left - 1; i <= right - 1; i++)
            res = (res + subSum[i]) % mod;

        return res;
    }
};
