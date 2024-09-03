//M1
//Using bit manipulation and basic maths
//Faster than 100% (0ms)

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prev = n % 2;
        n /= 2;
        while (n > 0) {
            int curr = n % 2;
            if (curr == prev)
                return 0;
            n /= 2;
            prev = curr;
        }
        return 1;
    }
};
