//M1
//Using trie concept
//Faster than 100% (0ms)

class Solution {
public:
    long long diffCalculator(int n, long long st, long long end) {
        long long steps = 0;
        while (st <= n) {
            steps += min((long long)n + 1, end) - st;
            st *= 10;
            end *= 10;
        }
        return steps;
    }
    int findKthNumber(int n, int k) {
        long long curr = 1;
        k--;
        while (k > 0) {
            long long diff = diffCalculator(n, curr, curr + 1);
            if (diff <= k) {
                curr++;
                k -= diff;
            } else {
                curr *= 10;
                k--;
            }
        }
        return curr;
    }
};
