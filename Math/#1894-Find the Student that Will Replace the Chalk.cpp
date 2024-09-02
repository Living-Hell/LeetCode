//M1
//Using simulation and basic maths
//Faster than 88.75% (85ms)

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long n = chalk.size(), i = 0, tsum = 0;

        for (int i = 0; i < n; i++)
            tsum += chalk[i];
        k %= tsum;

        while (1) {
            if (chalk[i] > k)
                return i;
            k -= chalk[i];
            i = (i + 1) % n;
        }
        return 0;
    }
};
