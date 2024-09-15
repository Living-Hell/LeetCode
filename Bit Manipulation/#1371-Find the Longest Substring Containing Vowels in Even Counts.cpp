//M1
//Using bit manipulation
//Faster than 15.12% (99ms)

class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_set<char> st = {'a', 'e', 'i', 'o', 'u'};
        int n = s.size(), cnt = 0, res = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;

        for (int i = 0; i < n; i++) {
            char c = s[i];
            int curr = c - 'a';
            if (st.contains(c))
                cnt ^= (1 << curr);
            if (mp.count(cnt)) {
                res = max(res, i - mp[cnt]);
            } else {
                mp[cnt] = i;
            }
        }
        return res;
    }
};
