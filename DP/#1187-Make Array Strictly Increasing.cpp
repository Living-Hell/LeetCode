//M1
//Using DP (Recursion + Memoisation)
//Faster than 71.76% (280 ms)

class Solution {
public:
    int dp[2001][2001][2];
    int solve(vector<int>& arr1, vector<int>& arr2, int ind1, int ind2,
              int prev, bool flag) {
        if (ind1 == arr1.size())
            return 0;

        if (dp[ind1][ind2][flag] != -1)
            return dp[ind1][ind2][flag];

        while (ind2 < arr2.size() and arr2[ind2] <= prev)
            ind2++;

        if (arr1[ind1] <= prev and ind2 == arr2.size())
            return 2001;

        int resA = 2001, resB = 2001;

        if (arr1[ind1] > prev)
            resA = solve(arr1, arr2, ind1 + 1, ind2, arr1[ind1], false);
        if (ind2 != arr2.size())
            resB = 1 + solve(arr1, arr2, ind1 + 1, ind2 + 1, arr2[ind2], true);

        return dp[ind1][ind2][flag] = min(resA, resB);
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        vector<int> arr3;
        for (int& i : arr2) {
            if (!arr3.size() || arr3.back() != i)
                arr3.push_back(i);
        }
        memset(dp, -1, sizeof(dp));
        int res = solve(arr1, arr2, 0, 0, -1, false);
        return res > arr1.size() ? -1 : res;
    }
};
