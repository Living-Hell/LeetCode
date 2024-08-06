//M1
//Using Greedy
//Faster than 83.57% (67ms)

class Solution {
public:
    int minimumPushes(string word) {
        int a[26] = {0};
        for (char& c : word)
            a[c - 'a']++;

        vector<pair<int, int>> v;
        for (int i = 0; i < 26; i++)
            v.push_back({a[i], i});

        sort(v.begin(), v.end(), greater<pair<int, int>>());

        int res = 0, ind = 1, factor = 1;
        for (int i = 0; i < v.size(); i++) {
            res += v[i].first * factor;
            ind++;
            if (ind == 9) {
                ind = 1;
                factor++;
            }
        }
        return res;
    }
};
