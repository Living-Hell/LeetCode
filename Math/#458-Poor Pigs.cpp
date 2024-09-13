//M1
//Using math
//Faster than 55.75% (2ms)

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int tests = minutesToTest / minutesToDie, i = 0;
        while(pow(tests + 1, i) < buckets)
            i++;
        return i;
    }
};
