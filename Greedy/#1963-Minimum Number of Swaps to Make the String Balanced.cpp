//M1
//Using greedy approach
//Faster than 44.77% (111 ms)

class Solution {
public:
    int minSwaps(string s) {
        int n = s.size(), ind = 0, count = 0, res = 0, j = n-1;
        while (ind < n) {
            if (s[ind] == '[')
                count++;
            else {
                if (count == 0) {
                    while (j > ind) {
                        if (s[j] == '[') {
                            swap(s[j], s[ind]);
                            res++;
                            count++;
                            break;
                        }
                        j--;
                    }
                } else {
                    count--;
                }
            }
            ind++;
        }
        return res;
    }
};
