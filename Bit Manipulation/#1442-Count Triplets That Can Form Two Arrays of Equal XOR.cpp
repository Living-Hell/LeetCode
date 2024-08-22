//M1
//Using Bit Manipulation
//Faster than 100% (0ms)

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int res = 0;

        for (int i = 1; i <= n; i++) {
            int xorAll = 0, j = 0;
            for (; j < i; j++) {
                xorAll ^= arr[j];
            }
            if (xorAll == 0)
                res += i - 1;
            while (j < n) {
                xorAll ^= arr[j - i];
                xorAll ^= arr[j];
                if (xorAll == 0)
                    res += i - 1;
                j++;
            }
        }

        return res;
    }
};
