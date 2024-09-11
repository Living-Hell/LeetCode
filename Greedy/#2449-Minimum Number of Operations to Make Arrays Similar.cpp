//M1
//Using sorting and greedy
//Faster than 40.47% (147ms)

class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        long long res = 0;
        int n = nums.size(), i = 0, j = n - 1;

        sort(nums.begin(), nums.end());
        sort(target.begin(), target.end());

        vector<int> a, b;
        for (int i : nums)
            if (i & 1)
                a.push_back(i);
        for (int i : target)
            if (i & 1)
                b.push_back(i);
        for (int i : nums)
            if (!(i & 1))
                a.push_back(i);
        for (int i : target)
            if (!(i & 1))
                b.push_back(i);

        for (int i = 0; i < n; i++) {
            if (a[i] < b[i])
                res += (b[i] - a[i]) / 2;
        }

        return res;
    }
};
