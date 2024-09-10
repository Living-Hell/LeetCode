//M1
//Using sorting
//Faster than 92.45% (117 ms)

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<long long> v;

        for (int i = 0; i < n - 1; i++)
            v.push_back(weights[i] + weights[i + 1]);

        sort(v.begin(), v.end());
        k -= 1;

        long long low = 0, high = 0;
        for (int i = 0; i < k; i++) {
            low += v[i];
            high += v[n - 2 - i];
        }
        return high - low;
    }
};
