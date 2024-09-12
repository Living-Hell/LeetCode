//M1
//Using simulation and basic math
//Faster than 71.41% (44ms)

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int a[26] = {0};
        for (int i = 0; i < allowed.size(); i++) {
            a[allowed[i] - 'a']++;
        }

        int res = 0;

        for (string& s : words) {
            int b[26] = {0};
            for (int i = 0; i < s.size(); i++) {
                b[s[i] - 'a']++;
            }
            bool flag = 1;
            for (int i = 0; i < 26; i++) {
                if (a[i] == 0 and b[i] > 0) {
                    flag = 0;
                    break;
                }
            }
            res += flag;
        }
        return res;
    }
};
