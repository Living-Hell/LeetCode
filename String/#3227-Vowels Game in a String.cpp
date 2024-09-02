//M1
//Using intuition and basic logic
//Faster than 45.04% (47ms)

class Solution {
public:
    bool doesAliceWin(string s) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or
                s[i] == 'u') {
                return 1;
            }
        }
        return 0;
    }
};
