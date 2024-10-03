//M1
//Using sliding window and hashmap
//Faster than 6.17% (156ms)

class Solution {
public:
    bool checkEquality(unordered_map<char, int>& mp1,
                       unordered_map<char, int>& mp2) {
        for (auto& i : mp1) {
            if (mp2[i.first] < i.second)
                return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        unordered_map<char, int> mp1, mp2;
        for (char& c : t)
            mp1[c]++;
        int st = 0, end = 0, n = s.size();
        bool check = 0;
        int resSt = 0, resEnd = n - 1;

        while (end < n) {
            mp2[s[end]]++;
            if (checkEquality(mp1, mp2)) {
                check = 1;
                while (st <= end) {
                    if (!checkEquality(mp1, mp2))
                        break;
                    if (end - st + 1 < resEnd - resSt + 1) {
                        resSt = st, resEnd = end;
                    }
                    mp2[s[st]]--;
                    st++;
                }
            }
            end++;
        }
        string res = s.substr(resSt, resEnd - resSt + 1);
        return check ? res : "";
    }
};
