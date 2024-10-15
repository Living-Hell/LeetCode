//M1
//Using suffix sum
//Faster than 43.16% (35ms)

class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size(), count = 0, end = n - 1;
        long long res = 0;
        while (end >= 0) {
            if (s[end] == '0')
                count++;
            else {
                res += count;
            }
            end--;
        }
        return res;
    }
};
