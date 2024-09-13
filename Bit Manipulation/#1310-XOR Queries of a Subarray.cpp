//M1
//Using bit manipulation
//Faster than 65.18% (59ms)

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> pref(n);
        pref[0] = arr[0];
        for (int i = 1; i < n; i++) {
            pref[i] = pref[i - 1] ^ arr[i];
        }
        vector<int> res;
        for (int i = 0; i < queries.size(); i++) {
            int a = queries[i][0], b = queries[i][1];
            int ans = pref[b];
            if (a > 0)
                ans ^= pref[a - 1];
            res.push_back(ans);
        }
        return res;
    }
};
